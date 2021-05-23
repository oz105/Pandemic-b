
#include <iostream>
#include <iomanip>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

int main (){


    // make level disease in the cities
    Board board ;
    board[City::Miami] = 3; // yellow color
    board[City::SaoPaulo] = 3; // yellow color
    board[City::NewYork] = 2; // blue color
    board[City::Madrid] = 5; // blue color
    board[City::Mumbai] = 4; // black color
    board[City::Karachi] = 3; // black color
    board[City::HongKong] = 2; // red color
    board[City::Shanghai] = 4; // red color


    cout << endl;
    cout << "Starting Game" << endl ;
    cout << board << endl ;


    OperationsExpert opertion_expert{board,City::Miami}; // can build in his city station with out use card
    opertion_expert.take_card(City::Milan);
    opertion_expert.take_card(City::Algiers);
    opertion_expert.take_card(City::Cairo);
    opertion_expert.take_card(City::SanFrancisco);
    opertion_expert.show_cards();

    GeneSplicer gene_splicer {board,City::Miami}; // can discover cure with 5 diffrent color
    gene_splicer.take_card(City::Lagos);//yellow
    gene_splicer.take_card(City::MexicoCity); //yellow
    gene_splicer.take_card(City::HoChiMinhCity);//red
    gene_splicer.take_card(City::Sydney);//red
    gene_splicer.take_card(City::Atlanta);//blue

    Medic medic {board,City::BuenosAires}; // will cure the city when arrived if there is cure for that coolor
    medic.take_card(City::Bangkok);
    medic.take_card(City::Bogota);
    medic.take_card(City::SaoPaulo);
    medic.take_card(City::Madrid);

    Virologist virologist {board,City::Baghdad};
    virologist.take_card(City::Algiers);
    virologist.take_card(City::Istanbul);
    virologist.take_card(City::Moscow);
    virologist.take_card(City::Tehran);
    virologist.take_card(City::Delhi);
    



    FieldDoctor field_doctor {board,City::Beijing}; // can use treat one neibors cities
    field_doctor.take_card(City::Tehran);
    field_doctor.take_card(City::Taipei);
    field_doctor.take_card(City::Tokyo);
    field_doctor.take_card(City::Kolkata);

    OperationsExpert opertion_expert2{board,City::Baghdad};

    opertion_expert.build();// now there is station in Miami 

    cout << "******* after build station in Miami *******" << endl ;
    cout << endl ;

    cout << board << endl ;

    opertion_expert2.build();// now there is station in Baghdad 

    cout << "******* after build station in Baghdad *******" << endl ;
    cout << endl ;

    cout << board << endl ;


    gene_splicer.discover_cure(Color::Yellow);

    cout << "******* after discover yellow cure  *******" << endl ;
    cout << endl ;
    
    cout << board << endl ;

    medic.drive(City::SaoPaulo); 

    cout << "******* after medic drive to Sao Paulo (yellow city) shuold cure all  *******" << endl ;
    cout << endl ;

    cout << board << endl ;

    medic.fly_charter(City::Madrid);
    medic.treat(City::Madrid);

    cout << "******* after medic use treat in Madrid (blue city) should cure all  *******" << endl ;
    cout << endl ;

    cout << board << endl ;




    field_doctor.treat(City::Shanghai) ;

    cout << "******* after field doctor use treat in Shanghai should be now 3  *******" << endl ;
    cout << endl ;

    cout << board << endl ;

    virologist.discover_cure(Color::Black); // now there is cure for balck color

    cout << "******* after virologist use discover cure for Black color  *******" << endl ;
    cout << endl ;

    cout << board << endl ;

    virologist.take_card(City::Mumbai);

    virologist.treat(City::Mumbai);

    cout << "******* after virologist use treat in Mumbai should be now 0 there is Black cure  *******" << endl ;

    cout << endl ;

    cout << board << endl ;

    virologist.take_card(City::HongKong);
    virologist.treat(City::HongKong);

     cout << "******* after virologist use treat in HongKong should be now 1 there is no Red cure  *******" << endl ;

    cout << endl ;

    cout << board << endl ;















     













    return 0 ;
}