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
void makeButtons(sf::RectangleShape button[],int number){
    for(int i=0; i<number; i++){
    button[i].setSize(Vector2f(220,110));
    button[i].setTexture(&t2);
    button[i].setPosition(Vector2f(50+250*i,640));
}}
void addText(sf::Text text[] , int number ){
    
    for(int i=0; i<number;i++){
        text[i].setFont(fd);
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

int main(){
sf::RenderWindow window (VideoMode(800,800),"Chess Game ");
t1.loadFromFile("screen1.png");
t2.loadFromFile("button.png");
fd.loadFromFile("fd.ttf");
sf:: RectangleShape screen1;
screen1.setSize(Vector2f(800,800));
screen1.setTexture(&t1);
sf:: RectangleShape button[3];
 makeButtons(button,3);
 sf:: Text text[3];

 addText(text,3);
 Vector2i c;
 int currscr=0;
 int i=0;
 


while(window.isOpen()){
    if(currscr==0){

    
    sf::Event event;
    c=Mouse::getPosition(window);
    while(window.pollEvent(event)){
        
        if(event.type==sf::Event::Closed){
            window.close();
        }
         
    }
    if(button[0].getGlobalBounds().contains(c.x,c.y)){
        i==1;
    }
    text[0].setFillColor(Color::White);
    text[1].setFillColor(Color::White);
    text[2].setFillColor(Color::White);
    
    if(i==1){
text[0].setFillColor(sf::Color(60, 40, 20));
    }

    window.clear();
    window.draw(screen1);
    drawButtons(window,button,3);
    drawText(window,text,3);
    
    window.display();
}
}

return 0;
}