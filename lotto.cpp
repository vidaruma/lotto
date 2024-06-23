#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;
int checker (vector<string> row) {
    int counter_num = 0;
    for (int col_num = 0;col_num<row.size() ; col_num++) {
        if (row[col_num] != "  ") {
            counter_num+=1;
        }

    }
    return counter_num;
}
string convertor (int number) {
    if (number<10) {
        string number_converted = to_string(number);
        string response = number_converted+" ";
        return response;
    } else {
        return to_string(number);
    }
}
int printer (vector<vector<string>> player ) {
    cout<<"------------------------------------------------------- \n";
    cout<<"| "<<player[0][0]<<"  | "<<player[0][1]<<"  | "<<player[0][2]<<"  | "<<player[0][3]<<"  | "<<player[0][4]<<"  | "<<player[0][5]<<"  | "<<player[0][6]<<"  | "<<player[0][7]<<"  | "<<player[0][8]<<"  | \n";
    cout<<"------------------------------------------------------- \n";
    cout<<"| "<<player[1][0]<<"  | "<<player[1][1]<<"  | "<<player[1][2]<<"  | "<<player[1][3]<<"  | "<<player[1][4]<<"  | "<<player[1][5]<<"  | "<<player[1][6]<<"  | "<<player[1][7]<<"  | "<<player[1][8]<<"  | \n";
    cout<<"------------------------------------------------------- \n";
    cout<<"| "<<player[2][0]<<"  | "<<player[2][1]<<"  | "<<player[2][2]<<"  | "<<player[2][3]<<"  | "<<player[2][4]<<"  | "<<player[2][5]<<"  | "<<player[2][6]<<"  | "<<player[2][7]<<"  | "<<player[2][8]<<"  | \n";
    cout<<"------------------------------------------------------- \n";



}
vector<vector<string>> c_creator (vector<int> player) {
    int column;
    int row;

    vector<vector<string>> card = {{"  ","  ","  ","  ","  ","  ","  ","  ","  "},{"  ","  ","  ","  ","  ","  ","  ","  ","  "},{"  ","  ","  ","  ","  ","  ","  ","  ","  "}};
    for (int number_crd = 0;number_crd<player.size();number_crd++) {

        while(true) {

//            for (int fow=0;fow<player.size();fow++) {
//                cout<<player[fow]<<"\n";
//            }


            row = rand () % 3;
            column=(player[number_crd] - player[number_crd] % 10) / 10;
            for (int card_c=0;card_c<card.size();card_c++){
               if ((9-column)==5-checker(card[card_c])) {
                    row=card_c;
               }
            }

            if (card[row][column] == "  " && checker(card[row])<5) {
                    //if (checker(card[row])==5) {
                        //cout<<"ok \n";
                    //}
                    if (checker(card[row])!=4 || player.size()-number_crd<=2 || (9-column)==5-checker(card[row]) || column>=3 ) {
                        card[row][column] = convertor(player[number_crd]);
                        break;
                    }
            }
        }



   }
   //cout<<printer(card)<<"\n";


    return card;
}


int check (int prew,int i) {
    int add = rand() % 10;
    add+=i*10;
    if (add==prew or add==0) {
       add=check(prew,i);
    }
    return add;
}
int counter(int players_num,int choose) {

    int end_game = false;
    vector<int> boch = {} ;

    vector<vector<int>> players = {};
    int num_of_pl = players_num ;
    //cin>>num_of_pl;
    int ctime_1 =time (NULL);
    //cout<<"\n \n";
    for (int rs = 0 ; rs<num_of_pl;rs++) {
        vector<int> player = {} ;
        int add = 0;
        int prew = 0 ;
        int maxi = 10;
        int ran = 3;
        int kol = 0;
        for (int i=0;i<9;i++){
            if (ran > 0) {
                kol = rand() % 2 + 1 ;
            } else {
                kol=2;
            }
            if (kol==0) {
                kol+=1;
            }
            if (i>=6 and ran>=1) {
                kol=1;
            }


            for (int raz=0;raz<kol;raz++) {
                add=check(prew,i);
                //if (add==0) {
                //    add+=1;
                //}
                player.push_back(add);
                prew=add;
            }

            if (kol==1) {
                ran-=1;
            }


        }

        sort(begin(player), end(player));
        players.push_back(player);
        if (choose==2) {
            printer(c_creator(player));
            cout<<"\n"<<"\n";
        }


        for (int c=0;c<player.size();c++) {

            //cout<<player[c]<<"\n";
        }
        //cout<<"player \n";
        //cout<<"\n \n";
    }
    for (int re=1;re<=90;re++) {
         boch.push_back(re);
    }
    for (int yu = 1;yu<=90;yu++) {
       int zx = rand() % boch.size();
       for (int ti = 0;ti<players.size();ti++) {
            for (int in = 0 ;in<players[ti].size() ; in++ ) {
                //cout<<players[ti][in]<<"\n";
                if (boch[zx]==players[ti][in]) {
                    players[ti].erase(players[ti].begin()+in);

                }
            }

       }
       boch.erase(boch.begin()+zx);
       for (int mk=0;mk<players.size();mk++){
            if (players[mk].size()==0) {
                if (choose==2) {
                     cout<<mk+1<<" won"<<"\n \n";
                }

                //cout<<yu<<"\n";
                return yu;
                end_game=true;
            }
       }
        if (end_game==true) {
            break;
        }
    }
    int ctime_2 =time (NULL);

    //cout<<ctime_2-ctime_1;

}
int main() {
    cout<<"choose game mode 1 or 2\n \n";
    cout<<"1 => average of players  \n \n       or \n \n";
    cout<<"2 => create and simulate cards and the game of loto \n \n";
    srand(time(0));
    int choose = 0;
    cin>>choose;
    int otvet = 0;
    vector<int> result = {};
    int list_[16] = {1,2,3,5,20,150,240,350,470,670,850,1150,2000,5000,10000,20000};


    if (choose==1) {
        for (int jk =0 ;jk<16;jk++) {
            for (int er = 0;er<50;er++) {
                otvet+=counter(list_[jk],choose);
            }
            cout<<"average => "<<otvet/50<<"  ";
            cout<<"players => "<<list_[jk]<<"\n";
            otvet=0;
        }
    }
    if (choose==2) {
        cin>>otvet;
        cout<<counter(otvet,choose)<<"\n";
    }


}

