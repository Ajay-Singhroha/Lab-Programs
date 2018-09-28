#include <iostream>
#define MAX 30
using namespace std;
class Diagonal
{
private:
    int arr[MAX];
    int size;
public:
    Diagonal(int s)
    {
        size=s;
        int i=0;
        while(i<size)
        {
            arr[i]=0;
            i++;
        }
    }
    void set(int i,int value)
    {
        arr[i]=value;
    }
    int get(int i)
    {
        return arr[i];
    }
};
class LowerTri
{
private:
    int arr[MAX];
    int size;
public:
    LowerTri(int s)
    {
        size=s*(s+1)/2;
        int i=0;
        while(i<size)
        {
            arr[i]=0;
            i++;
        }
    }
    void set(int i,int j,int value)
    {
        arr[i*(i+1)/2+j]=value;
    }
    int get(int i,int j)
    {
        return arr[i*(i+1)/2+j];
    }
};
class UpperTri
{
private:
    int arr[MAX];
    int size;
public:
    UpperTri(int s)
    {
        size=s*(s+1)/2;
        arr[size]= {0};
    }
    void set(int i,int j,int value)
    {
        arr[size*(size+1)/2-((size-i)*(size-i+1)/2)+(j-i)]=value;
    }
    int get(int i,int j)
    {
        return arr[size*(size+1)/2-((size-i)*(size-i+1)/2)+(j-i)];
    }
};
class TriDiagonal
{
private:
    int arr[MAX];
    int size;
public:
    TriDiagonal(int s)
    {
        size=s+2*(s-1);
        int i=0;
        while(i<size)
        {
            arr[i]=0;
            i++;
        }

        for(int i=0; i<size; i++)
            cout<<" "<<arr[i];
    }
    void set(int i,int j,int value)
    {
        switch(i-j)
        {
        case 1:
            arr[i-2]=value;
            break;
        case 0:
            arr[size+i-2]=value;
            break;
        case -1:
            arr[2*size+i-2]=value;
            break;
        }

    }
    int get(int i,int j)
    {
        switch(i-j)
        {
        case 1:
            return arr[i-2];
            break;
        case 0:
            return arr[size+i-2];
            break;
        case -1:
            return arr[2*size+i-2];
            break;
        default:
            return 0;
        }
    }
};
int main()
{

    int choice;
    do
    {

        cout<<"\n\n\n \t MENU ";
        cout<<"\n\n 1. Diagonal Matrix .";
        cout<<"\n\n 2. Lower Triangular Matrix .";
        cout<<"\n\n 3. Upper Triangular Matrix .";
        cout<<"\n\n 4. Tri - Diagonal Matrix .";
        cout<<"\n\n 5. Exit .";
        cout<<"\n\n\n Enter Your choice :: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            int s,value,i,j,choice_d;
            cout<<"\n Enter Size of Matrix :: ";
            cin>>s;
            Diagonal d(s);
            do
            {
                cout<<"\n\n   Menu   ";
                cout<<"\n\n  1. Set Values .";
                cout<<"\n\n  2. Get Values .";
                cout<<"\n\n  3. Display .";
                cout<<"\n\n  4. Exit . ";
                cout<<"\n\n\n Enter Your Choice :: ";
                cin>>choice_d;
                switch(choice_d)
                {
                case 1:
                    cout<<"\n Enter Values :: ";
                    for(int i=0; i<s; i++)
                    {
                        cout<<"\n Enter for A["<<i+1<<"]["<<i+1<<"] :: ";
                        cin>>value;
                        d.set(i,value);
                    }
                    break;
                case 2:
                    cout<<"\n Enter Index Values : ";
                    try
                    {

                        cout<<"\n Index Value of i :: ";
                        cin>>i;
                        cout<<"\n Index Value of j :: ";
                        cin>>j;
                        if(i>s||j>s||i<=0||j<=0)
                            throw i;
                        else
                        {
                            if(i==j)
                                cout<<"\n Value ::"<<d.get(i-1);
                            else
                                cout<<"\n Value :: 0 ";
                        }
                    }
                    catch(int error)
                    {
                        cout<<"\n Error ,Wrong Index Value ! ";
                        return 0;
                    }

                    break;
                case 3:
                    cout<<"\n";
                    for(int i=0; i<s; i++)
                    {
                        for(int j=0; j<s; j++)
                        {
                            if(i==j)
                                cout<<""<<d.get(i)<<" ";
                            else
                                cout<<""<<0<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                case 4:
                    break;
                default :
                    cout<<"\n WRONG CHOICE ";
                }
            }
            while(choice_d<4);
        }
        break;

        case 2:
        {
            int s=0,value=0,i=0,j=0,choice_l=0;
            cout<<"\n Enter Size of Matrix :: ";
            cin>>s;
            LowerTri d(s);
            do
            {
                cout<<"\n\n   Menu   ";
                cout<<"\n\n  1. Set Values .";
                cout<<"\n\n  2. Get Values .";
                cout<<"\n\n  3. Display .";
                cout<<"\n\n  4. Exit . ";
                cout<<"\n\n\n Enter Your Choice :: ";
                cin>>choice_l;
                switch(choice_l)
                {
                case 1:
                    cout<<"\n Enter Values (for Lower Tri Entries Only ):: ";
                    for(int i=0; i<s; i++)
                    {
                        for(int j=0; j<=i; j++)
                        {
                            cout<<"\n Enter for A["<<i+1<<"]["<<j+1<<"] :: ";
                            cin>>value;
                            d.set(i,j,value);
                        }
                    }
                    break;
                case 2:
                    cout<<"\n Enter Index Values : ";
                    try
                    {

                        cout<<"\n Index Value of i :: ";
                        cin>>i;
                        cout<<"\n Index Value of j :: ";
                        cin>>j;
                        if((i>s||j>s)||(i<=0||j<=0))
                            throw i;
                        else
                        {
                            if(i>=j)
                                cout<<"\n Value ::"<<d.get(i-1,j-1);
                            else
                                cout<<"\n Value :: 0 ";
                        }
                    }

                    catch(int error)
                    {
                        cout<<"\n Error ,Wrong Index Value ! ";
                        return 0;
                    }

                    break;
                case 3:
                    cout<<"\n";
                    for(int i=0; i<s; i++)
                    {
                        for(int j=0; j<s; j++)
                        {
                            if(i>=j)
                                cout<<""<<d.get(i,j)<<" ";
                            else
                                cout<<""<<0<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                case 4:

                    break;
                default :
                    cout<<"\n WRONG CHOICE ";
                }
            }
            while(choice_l<4);
        }
        break;

        case 3:
        {
            int s=0,value=0,i=0,j=0,choice_u=0;
            cout<<"\n Enter Size of Matrix :: ";
            cin>>s;
            UpperTri d(s);
            do
            {
                cout<<"\n\n   Menu   ";
                cout<<"\n\n  1. Set Values .";
                cout<<"\n\n  2. Get Values .";
                cout<<"\n\n  3. Display .";
                cout<<"\n\n  4. Exit . ";
                cout<<"\n\n\n Enter Your Choice :: ";
                cin>>choice_u;
                switch(choice_u)
                {
                case 1:
                    cout<<"\n Enter Values (for Upper Tri Entries Only ):: ";
                    for(int i=0; i<s; i++)
                    {
                        for(int j=i; j<s; j++)
                        {
                            cout<<"\n Enter for A["<<i+1<<"]["<<j+1<<"] :: ";
                            cin>>value;
                            d.set(i,j,value);
                        }
                    }
                    break;
                case 2:
                    cout<<"\n Enter Index Values : ";
                    try
                    {

                        cout<<"\n Index Value of i :: ";
                        cin>>i;
                        cout<<"\n Index Value of j :: ";
                        cin>>j;
                        if(i>s||j>s||i<=0||j<=0)
                            throw i;
                        else
                        {
                            if(i<=j)
                                cout<<"\n Value ::"<<d.get(i-1,j-1);
                            else
                                cout<<"\n Value :: 0 ";
                        }
                    }
                    catch(int error)
                    {
                        cout<<"\n Error ,Wrong Index Value ! ";
                        return 0;
                    }

                    break;
                case 3:
                    cout<<"\n";
                    for(int i=0; i<s; i++)
                    {
                        for(int j=0; j<s; j++)
                        {
                            if(i<=j)
                                cout<<""<<d.get(i,j)<<" ";
                            else
                                cout<<""<<0<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                case 4:

                    break;
                default :
                    cout<<"\n WRONG CHOICE ";
                }
            }
            while(choice_u<4);
        }
        break;

        case 4:
        {
            int s=0,value=0,i=0,j=0,choice_t=0;
            cout<<"\n Enter Size of Matrix :: ";
            cin>>s;
            TriDiagonal d(s);
            do
            {
                cout<<"\n\n   Menu   ";
                cout<<"\n\n  1. Set Values .";
                cout<<"\n\n  2. Get Values .";
                cout<<"\n\n  3. Display .";
                cout<<"\n\n  4. Exit . ";
                cout<<"\n\n\n Enter Your Choice :: ";
                cin>>choice_t;
                switch(choice_t)
                {
                case 1:
                    cout<<"\n Enter Values for Lower Diagonal :: ";

                    for(int i=2; i<=s; i++)
                    {
                        for(int j=i-1; j<i; j++)
                        {
                            cout<<"\n Enter for A["<<i<<"]["<<j<<"] :: ";
                            cin>>value;
                            d.set(i,j,value);
                        }
                    }
                    cout<<"\n Enter Values for Upper Diagonal :: ";

                    for(int i=1; i<s; i++)
                    {
                        for(int j=i+1; j<i+2; j++)
                        {
                            cout<<"\n Enter for A["<<i<<"]["<<j<<"] :: ";
                            cin>>value;
                            d.set(i,j,value);
                        }
                    }
                    cout<<"\n Enter Values for Main Diagonal :: ";

                    for(int i=1; i<=s; i++)
                    {
                        cout<<"\n Enter for A["<<i<<"]["<<i<<"] :: ";
                        cin>>value;
                        d.set(i,i,value);
                    }
                    break;
                case 2:
                    cout<<"\n Enter Index Values : ";
                    try
                    {

                        cout<<"\n Index Value of i :: ";
                        cin>>i;
                        cout<<"\n Index Value of j :: ";
                        cin>>j;
                        if((i>s||j>s)||(i<=0||j<=0))
                            throw i;
                        else
                        {
                            cout<<"\n Value ::"<<d.get(i,j);

                        }
                    }

                    catch(int error)
                    {
                        cout<<"\n Error ,Wrong Index Value ! ";
                        return 0;
                    }

                    break;
                case 3:
                    cout<<"\n";
                    for(int i=1; i<=s; i++)
                    {
                        for(int j=1; j<=s; j++)
                        {
                            if(i==j||i==j-1||i==j+1)
                                cout<<""<<d.get(i,j)<<" ";
                            else
                                cout<<""<<0<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                case 4:

                    break;
                default :
                    cout<<"\n WRONG CHOICE ";
                }
            }
            while(choice_t<4);
        }
        break;

        case 5:
            break;
        default:
            cout<<"\n\n WRONG CHOICE !! ";
            break;

        }
    }
    while(choice<5);

    return 0;
}
