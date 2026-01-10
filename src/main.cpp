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
class Screen2{
    private:
    sf::RenderWindow & window;
    sf::RectangleShape s1;
    sf::Texture  screen;
    sf::Texture whitesMoves[6];
    sf::Texture blackMoves[6];
    public:
    Screen2(RenderWindow & wind) : window(wind){

    }
    void loadTextures(){
        s1.setSize(Vector2f(800,600));
        screen.loadFromFile("assests/board.png");
        s1.setTexture(&screen);
    }
void drawScreen(){
    window.draw(s1);
}

};

int main(){
    sf:: Texture t1,t2,t3;
 sf::Font fd;
sf::RenderWindow window (VideoMode(800,800),"Chess Game ");
t1.loadFromFile("screen1.png");
t2.loadFromFile("button.png");
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
    
    window.display();
}else if(currscr==1){
     
    sf::Event event;
    c=Mouse::getPosition(window);
    while(window.pollEvent(event)){
        
        if(event.type==sf::Event::Closed){
            window.close();
        }
        if(event.type==Event::KeyPressed){
        if(event.key.code==Keyboard::Escape){
            currscr=0;
        }
        }
    }
    window.clear();
    window.draw(screen1);
    scr2.drawScreen();
    window.display();

}
}


return 0;
}