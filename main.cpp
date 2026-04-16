#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

class Card{
    private:
        std::vector<char>valueCardUI {'J', 'Q', 'K', 'A'};
    public:
        char suitCard;
        int valueCard;
        void PrintCard(){
            std::cout << suitCard << " ";
            if(valueCard > 1)// to check whether J card and above or not
                std::cout << valueCardUI[valueCard-2]<< '\n';
            else
                std::cout << valueCard+9<<'\n' ;
        }
      Card(char suit, int value) {
        suitCard = suit;
        valueCard = value;
    }

};
class Deck{
    public:
        char trumpSuit;
        std::vector<Card> deck;
        Deck(){
            int size = 24;
            char suits[4] = {'H', 'D', 'S', 'C'};
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 6; j++)
                {   
                    Card a (suits[i], j);
                    deck.push_back(a);
                }
                
            }
            
        }
        void shuffle();

    
};

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(),deck.end(), g);
    std::cout << "Deck shuffled.\n";
}

class Table{
    public:
        std::vector<Card>tableAtt;
        std::vector<Card>tableDef;
        std::vector<Card>playerHand1;
        std::vector<Card>playerHand2;
        void printHand(std::vector<Card> &playerHand)
        {
            for(Card i: playerHand)
            {
               i.PrintCard();
            }
        }
        void dealCard(std::vector<Card> &playerHand1, std::vector<Card> &playerHand2, std::vector<Card> &deck){
            int i = 0;
            while(i<12){
                i+=2;
                playerHand1.push_back(deck[i-1]);
                playerHand2.push_back(deck[i-2]);
                
            }
        }

};

int main()
{
    Deck dec;
    for (int i = 0; i < 24; i++)
    {
        dec.deck[i].PrintCard();
    }
    std::cout << '\n';
    dec.shuffle();
    for (int i = 0; i < 24; i++)
    {
        dec.deck[i].PrintCard();
    }
    Table table;
    std::cout << "123123\n";
    table.dealCard(table.playerHand1, table.playerHand2, dec.deck);
    std::cout << "Print hand \n\n";
    table.printHand(table.playerHand1);

}