#include <iostream>
#include <string>

using namespace std;
class Figure {
private: //encapsuled
    int row;
    int col;
    string name;
    int** matrix;
    void reuse(int r,int c){
        row=r;
        col=c;
        //dynamic memory allocation of 2D pointers
        if(r>0 && c>0){
            matrix=new int *[r];
            for (int i=0;i<r;i++){
                matrix[i]=new int[c];
            }
        }
        else{
            matrix=NULL;
        }
    }
    void reuse_clean(){
        if(matrix != NULL){
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
            for(int i=0;i<row;i++){
                delete[] matrix[i];
            }
            delete[]matrix;
        }
    row=0;
    col=0;
    matrix=NULL;
    }
public:
    Figure(){
        reuse(0,0);
        name="";
        matrix=NULL;
        cout<<"Figure created with default values"<<endl;
    }
    Figure(int r,int c,int *data){
        reuse(r,c);
        //conversion from 1D to 2D
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++){
                matrix[i][j]=data[i*c+j];
            }
        }
        if(r==2 && c==2){
            name="Line 2D";
        }
        else if(r==2&& c==3){
            name="Line 3D";
        }
        else if(r==3&& c==2){
            name="Triangle 2D";
        }
        else if(r==3&& c==3){
            name="Triangle 3D";
        }
        else if(r==4 && c==2){
            name="Rectangle 2D";
        }
        else if(r==4 && c==3){
            name="Rectangle 3D";
        }
        else{
            name="Unknown Figure";
            cout<<"Please enter a valid figure"<<endl;
        }
        cout<<"Figure created with Given Values:"<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Rows:"<<r<<endl;
        cout<<"Column:"<<c<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<matrix[i][j]<<" " ;
            }
            cout<<endl;
        }
    }
    Figure(Figure &copy){
        reuse(copy.row,copy.col);
        name=copy.name;
        cout<<"Clone created from the figure:"<<endl;
        cout<<"Name:"<<copy.name<<endl;
        cout<<"Rows:"<<copy.row<<endl;
        cout<<"Column:"<<copy.col<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<copy.matrix[i][j]<<" " ;
            }
            cout<<endl;
        }
    }
    int getsum(){
        int sum=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                sum+=matrix[i][j];
            }
        }
        return sum;
    }
    int getsum(int x,int y){
        int sum=0;
        if(x>=row || y>=col){
            cout<<"Error:the input dimensions("<<x<<","<<y<<")must be less than the figure dimensions("<<row<<","<<col<<")"<<endl;
            return -1;
        }
        else{
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    sum+=matrix[i][j];
            }
        }
        }
        return sum;
     }
    ~Figure(){
    cout<<name<<" has been destroyed "<<endl;
    reuse_clean();
    }
;
};
int main(){
    Figure Shape;
    int datum[]={2,3,4,5,6,7,8,2,5,6,6,5};
    Figure shape(4,3,datum);
    Figure shape1=shape;
    cout<<"----summation tests----"<<endl;
    int test1=shape.getsum();
    cout<<"Test-01:Full Sum is:"<<test1<<endl;
    int test2=shape.getsum(3,4);
    cout<<"Test-02:Partial Sum(3,4) is:"<<test2<<endl;
    int test3=shape.getsum(1,2);
    cout<<"Test-03:Partial Sum(1,2) is:"<<test3<<endl;
    int test4=shape.getsum(2,1);
    cout<<"Test-04:Partial Sum(2,1) is:"<<test4<<endl;
    cout<<"----destructors running----"<<endl;
    return 0;
}
