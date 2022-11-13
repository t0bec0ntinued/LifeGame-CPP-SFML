
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <unistd.h>
#include <ctime>


using namespace sf;


const int windowWidth =320;
const int windowHeight=320;
bool newGen[windowHeight][windowWidth];
bool oldGen[windowHeight][windowWidth];
bool o[windowHeight][windowWidth];

int neighbour;


struct Cell{


    public:

        RectangleShape rect;




};




int rand_between(const int from, const int to) {

  if (to == from)
    return to;
  if (to < from)
    return rand_between(to, from);
  return from + rand() % (to-from+1);
}











void initMap(RenderWindow &window){
    Cell cell;
    cell.rect.setSize(Vector2f(3,3));
    for (int i = 0; i< windowHeight;i++){
         cell.rect.setPosition(cell.rect.getPosition().x,windowHeight - i*cell.rect.getSize().y);
        for (int j = 0; j< windowWidth;j++){
                cell.rect.setPosition(windowWidth-j*cell.rect.getSize().x,cell.rect.getPosition().y);
            newGen[i][j] = rand_between(0,1);
            if (newGen[i][j]==true){

                cell.rect.setFillColor(Color::Green);

            }
            else {

                cell.rect.setFillColor(Color::White);

            }

            window.draw(cell.rect);

        }
    }
    window.display();
}

void OldGen(){
    for(int i = 0; i < windowHeight; i++){

        for(int j = 0; j < windowWidth; j++){
            oldGen[i][j] = newGen[i][j];
        }
    }
}

void updateOldGen(){




     for(int i = 0; i < windowHeight; i++){

        for(int j = 0; j < windowWidth; j++){

                neighbour = 0;
               if (j==0){
                if(i==0){
                    if (oldGen[windowHeight-1][windowWidth-1]==true){
                            neighbour++;
                    }
                    if (oldGen[windowHeight-1][j]==true){
                            neighbour++;
                    }
                    if (oldGen[windowHeight-1][1]==true){
                            neighbour++;
                    }
                    if (oldGen[i][windowWidth-1]==true){
                            neighbour++;
                    }
                    if (oldGen[i][j]==true){

                            o[i][j]=true;
                    }
                    if (oldGen[i][j+1]==true){
                            neighbour++;
                    }
                    if (oldGen[i+1][windowWidth-1]==true){
                            neighbour++;
                    }
                    if (oldGen[i+1][j]==true){
                            neighbour++;
                    }
                    if (oldGen[i+1][j+1]==true){
                            neighbour++;
                    }
                }else if(i == windowHeight-1){
                    if (oldGen[i-1][windowWidth-1]==true){
                            neighbour++;
                    }
                    if (oldGen[i-1][j]==true){
                            neighbour++;
                    }
                    if (oldGen[i-1][j+1]==true){
                            neighbour++;
                    }
                    if (oldGen[i][windowWidth-1]==true){
                            neighbour++;
                    }
                    if (oldGen[i][j]==true){

                            o[i][j]=true;
                    }
                    if (oldGen[i][j+1]==true){
                            neighbour++;
                    }
                    if (oldGen[0][windowWidth-1]==true){
                            neighbour++;
                    }
                    if (oldGen[0][j]==true){
                            neighbour++;
                    }
                    if (oldGen[0][j+1]==true){
                            neighbour++;
                    }
                }
                else {
                if (oldGen[i-1][windowWidth-1]==true){
                           neighbour++;
                    }
                    if (oldGen[i-1][j]==true){
                           neighbour++;

                    }
                    if (oldGen[i-1][j+1]==true){
                           neighbour++;

                    }
                    if (oldGen[i][windowWidth-1]==true){
                           neighbour++;

                    }
                    if (oldGen[i][j]==true){

                            o[i][j]=true;
                    }
                    if (oldGen[i][j+1]==true){
                            neighbour++;
                    }
                    if (oldGen[i+1][windowWidth-1]==true){
                           neighbour++;
                    }
                    if (oldGen[i+1][j]==true){
                           neighbour++;
                    }
                    if (oldGen[i+1][j+1]==true){
                            neighbour++;

                    }

                }
               }else if(j==windowWidth-1){
                   if(i==0){
                    if (oldGen[windowHeight-1][j-1]==true){
                            neighbour++;

                    }
                    if (oldGen[windowHeight-1][j]==true){
                           neighbour++;

                    }
                    if (oldGen[windowHeight-1][0]==true){
                          neighbour++;

                    }
                    if (oldGen[i][j-1]==true){
                         neighbour++;

                    }
                    if (oldGen[i][j]==true){

                            o[i][j]=true;

                    }
                    if (oldGen[i][0]==true){
                          neighbour++;

                    }
                    if (oldGen[i+1][j-1]==true){
                           neighbour++;

                    }
                    if (oldGen[i+1][j]==true){
                          neighbour++;

                    }
                    if (oldGen[i+1][0]==true){
                          neighbour++;

                    }
                }else if(i == windowHeight-1){
                    if (oldGen[i-1][j-1]==true){
                           neighbour++;

                    }
                    if (oldGen[i-1][j]==true){
                           neighbour++;
                    }
                    if (oldGen[i-1][0]==true){
                           neighbour++;

                    }
                    if (oldGen[i][j-1]==true){
                           neighbour++;

                    }
                    if (oldGen[i][j]==true){

                            o[i][j]=true;
                    }
                    if (oldGen[i][0]==true){
                           neighbour++;

                    }
                    if (oldGen[0][j-1]==true){
                           neighbour++;

                    }
                    if (oldGen[0][j]==true){
                        neighbour++;

                    }
                    if (oldGen[0][0]==true){
                        neighbour++;

                    }
                }
                else if (i!=0 && i!=windowHeight-1){
                if (oldGen[i-1][j-1]==true){
                           neighbour++;
                    }
                    if (oldGen[i-1][j]==true){
                           neighbour++;
                    }
                    if (oldGen[i-1][0]==true){
                           neighbour++;

                    }
                    if (oldGen[i][j-1]==true){
                           neighbour++;
                    }
                    if (oldGen[i][j]==true){

                            o[i][j]=true;

                    }
                    if (oldGen[i][0]==true){
                          neighbour++;

                    }
                    if (oldGen[i+1][j-1]==true){
                         neighbour++;

                    }
                    if (oldGen[i+1][j]==true){
                           neighbour++;

                    }
                    if (oldGen[i+1][0]==true){
                           neighbour++;

                    }

                }
               }else if (j!=0 && j!=windowWidth-1){
                   if(i==0){
                    if (oldGen[windowHeight-1][j-1]==true){
                           neighbour++;
                    }
                    if (oldGen[windowHeight-1][j]==true){
                           neighbour++;

                    }
                    if (oldGen[windowHeight-1][j+1]==true){
                            neighbour++;
                    }
                    if (oldGen[i][j-1]==true){
                           neighbour++;

                    }
                    if (oldGen[i][j]==true){


                            o[i][j]=true;

                    }
                    if (oldGen[i][j+1]==true){
                          neighbour++;

                    }
                    if (oldGen[i+1][j-1]==true){
                           neighbour++;
                    }
                    if (oldGen[i+1][j]==true){
                          neighbour++;
                    }
                    if (oldGen[i+1][j+1]==true){
                          neighbour++;
                    }
                }else if(i == windowHeight-1){
                    if (oldGen[i-1][j-1]==true){
                           neighbour++;
                    }
                    if (oldGen[i-1][j]==true){
                           neighbour++;
                    }
                    if (oldGen[i-1][j+1]==true){
                           neighbour++;
                    }
                    if (oldGen[i][j-1]==true){
                           neighbour++;
                    }
                    if (oldGen[i][j]==true){


                            o[i][j]=true;
                    }
                    if (oldGen[i][j+1]==true){
                            neighbour++;
                    }
                    if (oldGen[0][j-1]==true){
                            neighbour++;
                    }
                    if (oldGen[0][j]==true){
                           neighbour++;
                    }
                    if (oldGen[0][j+1]==true){
                           neighbour++;
                    }
                }
                else if (i!=0&& i!=windowHeight-1){
                if (oldGen[i-1][j-1]==true){
                       neighbour++;
                    }
                    if (oldGen[i-1][j]==true){
                          neighbour++;
                    }
                    if (oldGen[i-1][j+1]==true){
                         neighbour++;
                    }
                    if (oldGen[i][j-1]==true){
                          neighbour++;
                    }
                    if (oldGen[i][j]==true){


                            o[i][j]=true;
                    }
                    if (oldGen[i][j+1]==true){
                           neighbour++;
                    }
                    if (oldGen[i+1][j-1]==true){
                          neighbour++;
                    }
                    if (oldGen[i+1][j]==true){
                          neighbour++;
                    }
                    if (oldGen[i+1][j+1]==true){
                        neighbour++;
                    }

                }
           }

 if (o[i][j]==true){

            if(neighbour < 2 || neighbour > 3){
                newGen[i][j] = false;

            }
            else  {
                newGen[i][j] = true;


            }

         }
         else if(o[i][j] != true ){
                if(neighbour != 3){
                    newGen[i][j] = false;

                }
                else {
                    newGen[i][j] = true;


                }

         }

        o[i][j]=false;


    }


}



}





void update(){
    OldGen();

    updateOldGen();

}
void render(RenderWindow &window){
 Cell cell;
    cell.rect.setSize(Vector2f(3,3));
    for (int i = 0; i< windowHeight;i++){
         cell.rect.setPosition(cell.rect.getPosition().x,windowHeight - i*cell.rect.getSize().y);
        for (int j = 0; j< windowWidth;j++){
                cell.rect.setPosition(windowWidth-j*cell.rect.getSize().x,cell.rect.getPosition().y);


            if (newGen[i][j]==true){

                cell.rect.setFillColor(Color::Green);

            }
            else {

                cell.rect.setFillColor(Color::White);

            }

            window.draw(cell.rect);

        }
    }

}

int main(){
    RenderWindow window(VideoMode(windowWidth,windowHeight),"Life SFML");
    window.setFramerateLimit(60);
    Event event;
    srand(time(NULL));
    initMap(window);

    while(window.isOpen()){
        while(window.pollEvent(event)){
                if(event.type==Event::Closed) window.close();
                else{
           window.clear(Color::White);
          update();
          render(window);
            window.display();
                }
        }
    }

}
