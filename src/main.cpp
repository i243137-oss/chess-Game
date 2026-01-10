#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void drawButtons(RenderWindow &window ,sf::RectangleShape button[],int number){
    for(int i=0; i<number; i++){
    window.draw(button[i]);
    }
}
void makeButtons(sf::RectangleShape button[],int number,sf::Texture *t2){
    for(int i=0; i<number; i++){
    button[i].setSize(Vector2f(220,110));
    button[i].setTexture(t2);
    button[i].setPosition(Vector2f(50+250*i,640));
}

}
int main(){
sf::RenderWindow window (VideoMode(800,800),"Chess Game ");
sf:: Texture t1,t2,t3;
t1.loadFromFile("screen1.png");
t2.loadFromFile("button.png");
sf:: RectangleShape screen1;
screen1.setSize(Vector2f(800,800));
screen1.setTexture(&t1);
sf:: RectangleShape button[3];
 makeButtons(button,3,&t2);


while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed){
            window.close();
        }
         
    }
    window.clear();
    window.draw(screen1);
    drawButtons(window,button,3);
    
    window.display();
}

return 0;
}