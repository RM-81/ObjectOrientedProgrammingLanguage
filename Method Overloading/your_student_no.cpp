//Include header files as required

using namespace std;
//===============================================================
class PartyMember{
	int member_id; //a unique ID assigned to each member by the political party
	string name; //name of the member
	long asset_value; //net asset of the member
    string nominated_for;  //name of the constituency if this member is nominated by his party for running election 
    //You are not allowed to add any other member variable in this class

	public:		
		//Write a default constructor for this class. Initialize data members as deem appropriate.
        
		//Write other parameterize constructors as required.
        
		//Write the setter functions for this class
        
        //Write the getter functions for this class
        		
		void show_member_details(){
            //Print member details in the format shown in the given sample output	            
		}
        //Add any other helper functions as required		
};
//===============================================================
class PoliticalParty{
	string name; //name of the political party
	PartyMember* members[1000]; //Array of pointers to PartyMember objects; Allocate an object to a pointer when a member is added. Assume that there will be at most 1000 members in a party
	int member_count; //count of members in the party
    
    //Add other member variables as required and justified

	public:		
		//Write a copy constructor for this class

        //Write other parameterize constructors as required

		//Write a destructor for this class

        //Write setter functions for this class

        //Write getter functions for this class
                
        PartyMember search_member(string constituency){
            //Returns the member nominated for the given constituency. If not found, return an empty object.
        }

        void join_party(PartyMember m){		
            //Add the member m to this party. Assign id sequentially to the new member.            
		}

		void join_party(PoliticalParty& pp){
            //Add all the members of pp to this party and remove them from pp. Assign ids sequentially to the new members in this party. When a member joins from one party to another, his nomination, if given, from the old party is automatically cancelled.           
		}

        void leave_party(int id){
            //Remove the member with the given id from this party. Rearrange the list such that all the members are consecutive, i.e., there is no hole in the list. When a member leaves a party, his id is never reused.
            
		}
		
        void nominate_member(int id, string constituency){
            //Nominate the member with given id for the constituency                        
        }

        void show_nominated_members(){
            //Show details of the members nominated for the election. Match the format as given in the expected output.                        
		}

        void cancel_nomination(int id){		
            //Cancel nomination of the member with the given id                        
		}

        PoliticalParty form_new_party(string name){	
            //Form a new party with the members who have been denied nomination	from this party            
		}

        void show_all_members(){
            //Print details info of all the members of this party in the format shown in the given expected output            
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