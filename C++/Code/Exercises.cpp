#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class ShowTicket{
    protected:
        bool sell;
        string row, num;
    public:
        ShowTicket (string a, string b){
            row = a;
            num = b;
            sell = false;
        }
        bool is_sold(){
            return sell;
        }
        void sell_seat(){
            sell = true;
        }
        string print_ticket(){
            stringstream ss;
            if (sell == true){
                ss<<row<<" "<<num<<" "<<"Sold";
            }
            else
                ss<<row<<" "<<num<<" "<<"Available";
            return ss.str();
        }
};

class SportTicket : public ShowTicket{
    bool beer;
    public:
        SportTicket(string row1, string num1):ShowTicket(row1, num1){
            beer = false;
        }
        bool beer_sold(){
            return beer;
        }
        void sell_beer(){
            beer = true;
        }
        string print_ticket(){
            stringstream ss1;
            if (sell == true){
                if (beer == true){
                    ss1<<row<<" "<<num<<" "<<"Sold "<<"beer";
                }
                else
                    ss1<<row<<" "<<num<<" "<<"Sold "<<"NoBeer";
            }
            else{
                if (beer == true){
                    ss1<<row<<" "<<num<<" "<<"Available "<<"beer";
                }
                else
                    ss1<<row<<" "<<num<<" "<<"Available "<<"NoBeer";
            }
            return ss1.str();
        }
};

int main(){
    SportTicket Tic1("AA","101");
    SportTicket Tic2("AA","102");
    Tic1.sell_seat();
    Tic2.sell_seat();
    Tic2.sell_beer();
    cout<<Tic1.print_ticket()<<endl;
    cout<<Tic2.print_ticket()<<endl;
    return 0;
}