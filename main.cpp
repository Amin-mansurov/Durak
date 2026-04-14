#include<iostream>
#include<vector>

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

    
};

int main()
{
    Deck dec;
    for (int i = 0; i < 24; i++)
    {
        dec.deck[i].PrintCard();
    }
    

}