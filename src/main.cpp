#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
sf:: Texture t1,t2,t3;
 sf::Font fd;

void drawButtons(RenderWindow &window ,sf::RectangleShape button[],int number){
    for(int i=0; i<number; i++){
    window.draw(button[i]);
    }
}
void makeButtons(sf::RectangleShape button[],int number,Texture * t2){
    for(int i=0; i<number; i++){
    button[i].setSize(Vector2f(220,110));
    button[i].setTexture(t2);
    button[i].setPosition(Vector2f(50+250*i,640));
}}
void addText(sf::Text text[] , int number ,Font *fd){
    
    for(int i=0; i<number;i++){
        text[i].setFont(*fd);
        text[i].setCharacterSize(28);
        if(i==0) text[i].setString("New Game");
        if(i==1) text[i].setString("Options");
        if(i==2) text[2].setString("Exit");
        text[i].setPosition(Vector2f(95+250*i,680));
        text[i].setStyle(Text::Bold);
    }
}
void drawText(RenderWindow & window,sf::Text text[],int number){
    for(int i=0; i<number;i++){
        window.draw(text[i]);
    }
}
/*class Node{
    public:
    Node * next;
    Node(){
        next=nullptr;
    }
};
class Move{
     bool player;
     Node * left;
     Node * right;
     Node * up;
     Node * down;
     Texture pieces[6];

     public:
    void  move(RectangleShape &m){
         if(m.getTexture()==(pieces+3)){
        

         }
     }


};
*/
class Screen2{
    private:
    sf::RenderWindow & window;
    sf::RectangleShape s1;
    sf::Texture  screen;
    Vector2i selected;
    Vector2i dest;
    bool select;
    public:
    sf::Texture whitesMoves[6];
    sf::Texture blackMoves[6];
    sf:: RectangleShape chess[8][8];

    public:
    Screen2(RenderWindow & wind) : window(wind){
        selected.x=selected.y=dest.x=dest.y=-1;
        select=false;
    }
    void loadTextures(){
        s1.setSize(Vector2f(800,800));
        screen.loadFromFile("assets/board.png");
        s1.setTexture(&screen);
        blackMoves[0].loadFromFile("assets/bb.png");
        blackMoves[1].loadFromFile("assets/bk.png");
        blackMoves[2].loadFromFile("assets/bkn.png");
        blackMoves[3].loadFromFile("assets/bp.png");
        blackMoves[4].loadFromFile("assets/bq.png");
        blackMoves[5].loadFromFile("assets/br.png");
         whitesMoves[0].loadFromFile("assets/wb.png");
          whitesMoves[1].loadFromFile("assets/wk.png");
           whitesMoves[2].loadFromFile("assets/wkn.png");
            whitesMoves[3].loadFromFile("assets/wp.png");
             whitesMoves[4].loadFromFile("assets/wq.png");
              whitesMoves[5].loadFromFile("assets/wr.png");








    }
    void loadChess(){
        for(int i=0; i<8;i++){
        for(int j=0;j<8; j++){
            chess[i][j].setSize(Vector2f(97.5,97.5));
            chess[i][j].setPosition(Vector2f(10+97.5*i,10+97.5*j));
            chess[i][j].setOutlineColor(Color::Yellow);
            chess[i][j].setFillColor(Color::Transparent);
            
            
           
        }
       
    }
    setBlackChess();
    setWhiteChess(whitesMoves);
    
    
    }
    
    void setBlackChess(){
        // black
        for( int i=0; i<8; i++){
        chess[i][1].setFillColor(Color::White);
        chess[i][1].setTexture(&blackMoves[3]);
        }
        chess[0][0].setFillColor(Color::White);
        
        chess[0][0].setTexture(&blackMoves[5]);
         chess[7][0].setFillColor(Color::White);
        chess[7][0].setTexture(&blackMoves[5]);

         chess[1][0].setFillColor(Color::White);
        chess[1][0].setTexture(&blackMoves[2]);
         chess[6][0].setFillColor(Color::White);
        chess[6][0].setTexture(&blackMoves[2]);

         chess[2][0].setFillColor(Color::White);
        chess[2][0].setTexture(&blackMoves[0]);
        chess[5][0].setFillColor(Color::White);
        chess[5][0].setTexture(&blackMoves[0]);

         chess[3][0].setFillColor(Color::White);
        chess[3][0].setTexture(&blackMoves[4]);

         chess[4][0].setFillColor(Color::White);
        chess[4][0].setTexture(&blackMoves[1]);
        Vector2f c=chess[0][0].getPosition();
        cout<<c.x<<"  "<<c.y<<endl;


        
    }
    void setWhiteChess(Texture blackMoves[]){
        
        for( int i=0; i<8; i++){
        chess[i][6].setFillColor(Color::White);
        chess[i][6].setTexture(&blackMoves[3]);
        }
        chess[0][7].setFillColor(Color::White);
        chess[0][7].setTexture(&blackMoves[5]);
         chess[7][7].setFillColor(Color::White);
        chess[7][7].setTexture(&blackMoves[5]);

         chess[1][7].setFillColor(Color::White);
        chess[1][7].setTexture(&blackMoves[2]);
         chess[6][7].setFillColor(Color::White);
        chess[6][7].setTexture(&blackMoves[2]);

         chess[2][7].setFillColor(Color::White);
        chess[2][7].setTexture(&blackMoves[0]);
        chess[5][7].setFillColor(Color::White);
        chess[5][7].setTexture(&blackMoves[0]);

         chess[3][7].setFillColor(Color::White);
        chess[3][7].setTexture(&blackMoves[4]);

         chess[4][7].setFillColor(Color::White);
        chess[4][7].setTexture(&blackMoves[1]);



        
    }
    void hoverAffect(){
        Vector2i c=Mouse::getPosition(window);
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(chess[i][j].getGlobalBounds().contains(c.x,c.y) && chess[i][j].getFillColor()==Color::Transparent){
                    chess[i][j].setOutlineThickness(3);
                    
                }else{
                    if(chess[i][j].getOutlineColor()==Color::Yellow)
                      chess[i][j].setOutlineThickness(0);
                      
                }
            }
        }
      
    }
    
void drawScreen(){
    window.draw(s1);
    for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            window.draw(chess[i][j]);
        }
    }
} 
int pollEvent(){
     sf::Event event;
     Vector2i c=Mouse::getPosition(window);
    while(window.pollEvent(event)){
        
        if(event.type==sf::Event::Closed){
            window.close();
        }
        if(event.type==Event::KeyPressed){
        if(event.key.code==Keyboard::Escape){
            return 0;
        }
        }
        if(event.type==Event::MouseButtonPressed){
            if(event.mouseButton.button==Mouse::Left){
            for(int i=0; i<8;i++){
                for(int j=0; j<8; j++){
                   if( chess[i][j].getGlobalBounds().contains(c.x,c.y) && chess[i][j].getFillColor()!=Color::Transparent){
                  selected.x=i;
                  selected.y=j;
                  select=true;
                  chess[i][j].setOutlineColor(Color::Green);
                  chess[i][j].setOutlineThickness(3);
                   }
                }
            }
            }
        }
        if(event.type==Event::MouseButtonPressed && select){
           if(event.mouseButton.button==Mouse::Right){
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                   if(chess[i][j].getGlobalBounds().contains(c.x,c.y) && chess[i][j].getFillColor()==Color::Transparent){
                    chess[i][j].setFillColor(Color::White);
                    chess[i][j].setTexture(chess[selected.x][selected.y].getTexture());
                    chess[selected.x][selected.y].setTexture(nullptr);
                     chess[selected.x][selected.y].setFillColor(Color::Transparent);
                     select=false;
                      chess[selected.x][selected.y].setOutlineColor(Color::Yellow);
                       chess[selected.x][selected.y].setOutlineThickness(3);
                   }
                }
            }

           }
        }
         
    }
   
    return 1;
}

};

int main(){
    sf:: Texture t1,t2,t3;
 sf::Font fd;
sf::RenderWindow window (VideoMode(800,800),"Chess Game ");
t1.loadFromFile("screen1.png");
t2.loadFromFile("button.png");
t3.loadFromFile("cursor.png");

RectangleShape cursor;

cursor.setTexture(&t3);
Screen2 scr2(window);

fd.loadFromFile("fd.ttf");
sf:: RectangleShape screen1;
screen1.setSize(Vector2f(800,800));
screen1.setTexture(&t1);
sf:: RectangleShape button[3];
 makeButtons(button,3,&t2);
 sf:: Text text[3];

 addText(text,3,&fd);
 Vector2i c;
 int currscr=0;
 int i=0;
 bool flag=true;
 


while(window.isOpen()){
    if(flag && currscr==1){
        scr2.loadTextures();
        scr2.loadChess();
        flag=false;
    }
    if(currscr==0){

    
    sf::Event event;
    c=Mouse::getPosition(window);
   
    while(window.pollEvent(event)){
        
        if(event.type==sf::Event::Closed){
            window.close();
        }
        if(event.type==Event::KeyPressed || event.type==Event::MouseButtonPressed){
           if (i==1 && event.mouseButton.button==Mouse::Right) currscr=1;
            if(event.key.code==Keyboard::Left){
                i--;
                if(i<1) i=3;
            }
             if(event.key.code==Keyboard::Right){
                i++;
                if(i>3) i=1;
              
            }
              if(i==1 && event.key.code==Keyboard::Enter ){
                    currscr=1;
                }
            
        }
         
    }
    if(button[0].getGlobalBounds().contains(c.x,c.y)){
       
        i=1;
    }
     if(button[1].getGlobalBounds().contains(c.x,c.y)){
       
        i=2;
    }
     if(button[2].getGlobalBounds().contains(c.x,c.y)){
       
        i=3;
    }
    text[0].setFillColor(Color::White);
    text[1].setFillColor(Color::White);
    text[2].setFillColor(Color::White);
   
    
    if(i==1 || i==2 || i==3 ){
text[i-1].setFillColor(sf::Color(60, 40, 20));
    }

    window.clear();
    window.draw(screen1);
    drawButtons(window,button,3);
    drawText(window,text,3);
    window.draw(cursor);
    
    window.display();
}else if(currscr==1){
  
    c=Mouse::getPosition(window);
   
   currscr=scr2.pollEvent();
    scr2.hoverAffect();
    window.clear();
    window.draw(screen1);
    scr2.drawScreen();
    window.draw(cursor);
    window.display();

}
}


return 0;
}