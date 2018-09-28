#include <iostream>

using namespace std;
void setValues_diagonal(int b[],int i,int value);
int getValues_diagonal(int b[],int i,int j);
void setValues_LowTri(int b[],int i,int j,int value);
int getValues_LowTri(int b[],int i,int j);
int main()
{
    int choice ;
    int value;
    int n,i,j;
    do
    {
        cout<<" \n\n    MENU    ";
        cout<<" \n\n 1. Diagonal Matrix ";
        cout<<" \n\n 2. Lower Triangular Matrix ";
        cout<<" \n\n 3. Upper Triangular Matrix ";
        cout<<" \n\n 4. Exit ";
        cout<<" \n\n Enter Your choice ::  ";
        cin>>choice;
        cout<<"\n Enter The size of Square Matrix :: ";
        cin>>n;
        int b[n*n]= {0};
        switch(choice)
        {
        case 1 :
        {
            int d_choice;
            do
            {
                cout<<"\n  1. Set Values  ";
                cout<<"\n  2. Get values ";
                cout<<"\n  3. Display ";
                cout<<"\n  4.Exit  ";
                cout<<"\n\n Enter your choice :: ";
                cin>>d_choice;
                switch(d_choice)
                {

                case 1:
                    for(int i=0; i<n; i++)
                    {
                        cout<<" Enter Value at Index  ["<<i<<"]["<<i<<"]  :: "  ;
                        cin>>value;
                        setValues_diagonal(b,i,value);
                    }
                    break;
                case 2:
                    do
                    {
                        cout<<"\n Enter Index Of array  \" i j \" :: ";
                        cin>>i;
                        cin>>j;
                        cout<<"\n  Value is "<<getValues_diagonal(b,i,j);
                        cout<<"\n\n Enter an Invalid Index To terminate ";
                    }
                    while((i>=0&&i<n)||(j>=0&&j<n));
                    break;
                default:
                    cout<<"\n WRong Choice ";
                    break;
                }
            }
            while(d_choice<4);
            case 2:
            {
                int l_choice;
                do
                {
                    cout<<"\n  1. Set Values  ";
                    cout<<"\n  2. Get values ";
                    cout<<"\n  3. Display ";
                    cout<<"\n  4.Exit  ";
                    cout<<"\n\n Enter your choice :: ";
                    cin>>l_choice;
                    switch(l_choice)
                    {

                    case 1:
                        for(int i=0; i<n; i++)
                        {
                            for(int j=0; j<=i; j++)
                            {
                                cout<<" Enter Value at Index  ["<<i<<"]["<<j<<"] :: ";
                                cin>>value;
                                setValues_LowTri(b,i,j,value);
                            }
                        }
                        break;
                    case 2:
                        do
                        {
                            cout<<"\n Enter Index Of array  \" i j \" :: ";
                            cin>>i;
                            cin>>j;
                            cout<<"\n  Value is "<<getValues_diagonal(b,i,j);
                            cout<<"\n\n Enter an Invalid Index To terminate ";
                        }
                        while((i>=0&&i<n)||(j>=0&&j<n));
                        break;
                    default:
                        cout<<"\n WRong Choice ";
                        break;
                    }
                }
                while(l_choice<2);
            }
            break;
        }

        }
        while(choice<5);
        return 0;
    }
    void setValues_diagonal(int b[],int i,int value)
    {
        b[i]=value;
    }
    int getValues_diagonal(int b[],int i,int j)
    {
        if(i!=j)
            return 0;
        else return b[i];
    }
    void setValues_LowTri(int b[],int i,int j,int value)
    {
        b[i*(i+1)/2 +j]=value;
    }
    int getValues_LowTri(int b[],int i,int j)
    {
        if(i>=j)
            return b[i*(i+1)/2 +j];
        else return 0;
    }

