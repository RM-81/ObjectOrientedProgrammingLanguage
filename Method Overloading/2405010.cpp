#include <iostream>
#include <string>

using namespace std;
//===============================================================
class PartyMember{
	int member_id; //a unique ID assigned to each member by the political party
	string name; //name of the member
	long asset_value; //net asset of the member
    string nominated_for; //name of the constituency if this member is nominated by his party for running election 
    //You are not allowed to add any other member variable in this class

	public:		
		//Write a default constructor for this class. Initialize data members as deem appropriate.
        PartyMember(){
            member_id=0;
            name="";
            asset_value=0;
            nominated_for="";
        }
    	//Write other parameterize constructors as required.
        PartyMember(string name,long asset){
            this->name=name;
            this->asset_value=asset;
        } 
        PartyMember(int id,string name,long asset,string nominated){
            this->member_id=id;
            this->name=name;
            this->asset_value=asset;
            this->nominated_for=nominated;
        }        
		//Write the setter functions for this class
        void set_id(int id){
            member_id=id;
        }
        void set_name(string s){
            name=s;
        }
        void set_asset(long asset){
            asset_value=asset;
        }
        void set_nominations(string nominated){
            nominated_for=nominated;
        }
        //Write the getter functions for this class
        int get_id(){
            return member_id; 
        }
        string get_name(){
            return name;
        }
        long get_asset(){
            return asset_value;
        }
        string get_nominations(){
            return nominated_for;
        }        		
		void show_member_details(){
            cout<<"ID: "<< get_id()<<", Name: "<<get_name()<<", Asset: "<<get_asset()<<", Constituency: "<<get_nominations()<<endl;
            //Print member details in the format shown in the given sample output	            
		}
        ~PartyMember(){
            this->member_id=0;
            this->name="";
            this->asset_value=0;
            this->nominated_for="";
        }
        //Add any other helper functions as required		
};
//===============================================================
class PoliticalParty{
	string name; //name of the political party
	PartyMember* members[1000]; //Array of pointers to PartyMember objects; Allocate an object to a pointer when a member is added. Assume that there will be at most 1000 members in a party
	int member_count; //count of members in the party
    //Add other member variables as required and justified
    int current_id=0; //to keep track of the most recently assigned member id(id never reused)
    

	public:		
		//Write a copy constructor for this class
        PoliticalParty(const PoliticalParty &other){
            this->name=other.name;
            this->member_count=other.member_count;
            this->current_id=other.current_id;
            for(int i=0;i<1000;i++){
                this->members[i]=new PartyMember(*(other.members[i]));//creates new objects and copies them
            }
        }

        //Write other parameterize constructors as required
        PoliticalParty(){
            name="";
            member_count=0;
            current_id=0;
            for(int i=0;i<1000;i++){
                members[i]=0;
            }
        }
        PoliticalParty(string name){
            this->name=name;
            for(int i=0;i<1000;i++){
                this->members[i]=0;
            }
            this->member_count=0;
            this->current_id=0;
        }
        //Write setter functions for this class
        void set_name(string p){
            name=p;
        }
        void set_member_count(int count){
            member_count=count;
        }
        void set_current_id(int curr){
            current_id=curr;
        }

        //Write getter functions for this class

        string get_name(){
            return name;
        }
        int get_member_count(){
            return member_count;
        }
        int get_current_id(){
            return current_id;
        }
        
        //other functions:
        
        PartyMember search_member(string constituency){
            int found=0;
            int idx=-1;
            for(int i=0;i<member_count;i++){
                if(members[i]->get_nominations()==constituency){
                    idx=i;
                    found=1; 
                    break;            
                }
            }
            if(found==1){
                return *members[idx];
            }
            else{
                return PartyMember();
            }
            //Returns the member nominated for the given constituency. If not found, return an empty object.
        }

        void join_party(PartyMember m){
            member_count= get_member_count();
            members[member_count]=new PartyMember (m); //copy constructor
            member_count++;
            current_id++;
            members[member_count-1]->set_id(current_id);
            //Add the member m to this party. Assign id sequentially to the new member.            
		}

		void join_party(PoliticalParty& pp){
            for(int i=0;i<pp.member_count;i++){
                pp.members[i]->set_nominations("");
            }
            int start1=this->member_count;
            this->member_count=this->member_count+pp.member_count;
            int end1=this->member_count;
            int start2=0;
            int end2=pp.member_count;
            while(start1!=end1 && start2!=end2){
                this->members[start1]=pp.members[start2];
                this->current_id++;    //I was doing with member_count but it fails when someone leaves;
                (this->members[start1])->set_id(current_id);
                start1++;
                start2++;
            }
            for(int i=0;i<pp.member_count;i++){
                pp.members[i]=nullptr;
            }
            pp.member_count=0;
            //Add all the members of pp to this party and remove them from pp. Assign ids sequentially to the new members in this party. When a member joins from one party to another, his nomination, if given, from the old party is automatically cancelled.           
		}

        void leave_party(int id){
            int idx=-1;
            int flag=0;
            for(int i=0;i<member_count;i++){
                if(members[i]->get_id()==id){
                    idx=i;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return;
            }
            else{
                delete members[idx];
                for(int i=idx;i<member_count-1;i++){
                    members[i]=members[i+1];
                }
                member_count--;
                members[member_count]=nullptr;
            }
            //Remove the member with the given id from this party. Rearrange the list such that all the members are consecutive, i.e., there is no hole in the list. When a member leaves a party, his id is never reused.    
		}
		
        void nominate_member(int id, string constituency){
            int idx=-1;
            int flag=0;
            for(int i=0;i<member_count;i++){
                if(members[i]->get_id()==id){
                    idx=i;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return;
            }
            else{
                members[idx]->set_nominations(constituency);
            }
            //Nominate the member with given id for the constituency                        
        }

        void show_nominated_members(){
            cout<<"Nominated Members of "<<get_name()<<":"<<endl;
            for(int i=0;i<member_count;i++){
                if(members[i]->get_nominations()!=""){
                    members[i]->show_member_details();
                }
            }
            //Show details of the members nominated for the election. Match the format as given in the expected output.                        
		}

        void cancel_nomination(int id){
            int idx=-1;
            int flag=0;
            for(int i=0;i<member_count;i++){
                if(members[i]->get_id()==id){
                    idx=i;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return;
            }
            else{
                members[idx]->set_nominations("");
            }	
            //Cancel nomination of the member with the given id                        
		}

        PoliticalParty form_new_party(string name){
            PoliticalParty P1(name);
            int idx_count=0;
            for(int i=0;i<member_count;i++){
                if(members[i]->get_nominations()==""){
                    idx_count++;
                }
            }
            if(idx_count==0){
                return P1;
            }
            int idx_setter[idx_count];
            int start=0;
            int end=member_count;
            int idx_start=0;
            int idx_end=idx_count;
            while(start<end && idx_start<idx_end){
                if(members[start]->get_nominations()==""){
                    P1.join_party(*members[start]);
                    idx_setter[idx_start]=start;
                    idx_start++;
                }
                start++;
            }
            for(int i=idx_count-1;i>=0;i--){
                this->leave_party(members[idx_setter[i]]->get_id());
            }
            return P1;
            //Form a new party with the members who have been denied nomination	from this party            	
    }
        void show_all_members(){
            cout<<"Members of "<<get_name()<<":"<<endl;
            if(member_count==0){
                cout<<"No members found."<<endl;
                cout<<endl;
                return;
            }
            for(int i=0;i<member_count;i++){
                if(members[i]->get_nominations()!=""){
                    members[i]->show_member_details();
                }
                else{
                    cout<<"ID: "<< members[i]->get_id()<<", Name: "<<members[i]->get_name()<<", Asset: "<<members[i]->get_asset()<<endl;   
                }
            }
            //Print details info of all the members of this party in the format shown in the given expected output            
		}

        //Write a destructor for this class
        ~PoliticalParty(){
            name="";
            current_id=0;
            for(int i=0;i<member_count;i++){
                delete members[i];
            }
            member_count=0;   
        }
        //Add any other helper function as required and justified
};
//=======================================
int main(){
    PartyMember abc1("Mr. A", 100000000);
    PartyMember abc2("Mr. B", 4000000);
    PartyMember abc3("Mr. C",20000000);
	PoliticalParty p1("ABC");
	p1.join_party(abc1);
	p1.join_party(abc2);
    p1.join_party(abc3);
	p1.show_all_members();

    p1.nominate_member(1,"DHK-10");
    PartyMember pm=p1.search_member("DHK-10");
    cout<<endl<<"Details of the member nominated for DHK-10 constituency:"<<endl;
    pm.show_member_details();

    p1.nominate_member(2,"CUM-3");
    p1.nominate_member(3,"SYL-1");
    p1.show_nominated_members();

    PartyMember xyz1("Mr. X", 1000000);
	PartyMember xyz2("Mr. Y", 3000000);
    	
    PoliticalParty p2("XYZ"); 
    p2.join_party(xyz1);
	p2.join_party(xyz2);
    p2.show_all_members();
    
    p1.join_party(p2);
    p1.show_all_members();
    p2.show_all_members();
    
    PartyMember xyz3("Mr. Z",5000000);
    p2.join_party(xyz3);
    p2.show_all_members();

	
    p1.cancel_nomination(1);
    p1.cancel_nomination(3);
    p1.nominate_member(4,"CUM-3");
    p1.nominate_member(5,"SYL-1");
    p1.show_nominated_members();    
    
    PoliticalParty p3=p1.form_new_party("Renegades");
    p1.show_all_members();
    p3.show_all_members();    
}

/* Expected Output
Members of ABC:
ID: 1, Name: Mr. A, Asset: 100000000
ID: 2, Name: Mr. B, Asset: 4000000
ID: 3, Name: Mr. C, Asset: 20000000

Details of the member nominated for DHK-10 constituency:
ID: 1, Name: Mr. A, Asset: 100000000, Constituency: DHK-10

Nominated Members of ABC:
ID: 1, Name: Mr. A, Asset: 100000000, Constituency: DHK-10
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 3, Name: Mr. C, Asset: 20000000, Constituency: SYL-1

Members of XYZ:
ID: 1, Name: Mr. X, Asset: 1000000
ID: 2, Name: Mr. Y, Asset: 3000000

Members of ABC:
ID: 1, Name: Mr. A, Asset: 100000000, Constituency: DHK-10
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 3, Name: Mr. C, Asset: 20000000, Constituency: SYL-1
ID: 4, Name: Mr. X, Asset: 1000000
ID: 5, Name: Mr. Y, Asset: 3000000

Members of XYZ:
No members found.

Members of XYZ:
ID: 3, Name: Mr. Z, Asset: 5000000

Nominated Members of ABC:
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 4, Name: Mr. X, Asset: 1000000, Constituency: CUM-3
ID: 5, Name: Mr. Y, Asset: 3000000, Constituency: SYL-1

Members of ABC:
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 4, Name: Mr. X, Asset: 1000000, Constituency: CUM-3
ID: 5, Name: Mr. Y, Asset: 3000000, Constituency: SYL-1

Members of Renegades:
ID: 1, Name: Mr. A, Asset: 100000000
ID: 2, Name: Mr. C, Asset: 20000000
*/