#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
float playerx=-70.0;
float playery=60;
float bot=-50;
float missel = 30;
int bot_voltar =0;
int voltarS=0;
char direcao;
int borda=1;


void desenhaMinhaCena()
{
    if(borda==1){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);

    //Escapamento do carrinho

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(playerx-23, playery+5, 0.0);
    glVertex3f(playerx-23, playery+1, 0.0);
    glVertex3f(playerx-13, playery+1, 0.0);

    // Carrinho

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(playerx, playery, 0.0);
    glVertex3f(playerx,playery+7 , 0.0); 
    glVertex3f(playerx+9, playery+7, 0.0);
    glVertex3f(playerx+9, playery+7, 0.0);
    glVertex3f(playerx+9, playery, 0.0);
    glVertex3f(playerx, playery, 0.0); 
    glVertex3f(playerx, playery, 0.0); 
    glVertex3f(playerx,playery+7 , 0.0); 
    glVertex3f(playerx-18, playery+7, 0.0); 
    glVertex3f(playerx-18, playery+7, 0.0); 
    glVertex3f(playerx-18, playery, 0.0); 
    glVertex3f(playerx, playery, 0.0); 
    glColor3f(0.0, 0.0, 1.0);

    //Rodas do carrinho

    glVertex3f(playerx+6, playery, 0.0); 
    glVertex3f(playerx+3, playery-6, 0.0); 
    glVertex3f(playerx+9, playery-6, 0.0); 
    glVertex3f(playerx-14, playery, 0.0); 
    glVertex3f(playerx-11, playery-6, 0.0); 
    glVertex3f(playerx-17, playery-6, 0.0);


    //BOT 1
    glColor3f(1, 1, 1);
    glVertex3f(bot, -80, 0.0); 
    glVertex3f(bot, -72, 0.0); 
    glVertex3f(bot+40, -80, 0.0); 
    glVertex3f(bot+40, -80, 0.0); 
    glVertex3f(bot+40, -72, 0.0); 
    glVertex3f(bot, -72, 0.0); 


    //rodas
    glColor3f(1, 1, 1);
    glVertex3f(bot+10, -80, 0.0); 
    glVertex3f(bot+5, -89, 0.0); 
    glVertex3f(bot+15, -89, 0.0); 
    glVertex3f(bot+30, -80, 0.0); 
    glVertex3f(bot+25, -89, 0.0); 
    glVertex3f(bot+35, -89, 0.0); 


    //Míssel
    glColor3f(1,0,0);
    glVertex3f(20, missel-30, 0.0);
    glVertex3f(-10, missel-30, 0.0); 
    glVertex3f(5, missel-55, 0.0); 
    glColor3f(1,1,1);
    glVertex3f(-10, missel, 0.0); 
    glVertex3f(20, missel, 0.0); 
    glVertex3f(20, missel-30, 0.0);
    glVertex3f(20, missel-30, 0.0);
    glVertex3f(-10, missel-30, 0.0); 
    glVertex3f(-10, missel, 0.0); 
    glEnd();
    glFlush();}

    if(playerx+9>100 || playerx-24<-100 || playery+10>100 || playery<-95){
    borda=0;} //identificação das bordas do mapa, caso encostar não há atualização da cena
}


void setup()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glPointSize(10);
	glLoadIdentity();
}

void teclasEspeciais(int key, int x, int y) {
    switch (key){//teclas especiais para captura das setinhas
    case GLUT_KEY_LEFT:
        {
            playerx = playerx-5;
            direcao = 'a';
            break;
        }
    case GLUT_KEY_UP:
        {
            playery = playery+5;
            direcao ='w';
            break;
        }
    case GLUT_KEY_RIGHT:
        {
            playerx = playerx+5;
            direcao ='d';
            break;
        }
    case GLUT_KEY_DOWN:
        {
            playery = playery-5;
            direcao ='s';
            break;
        }
    default:
        break;
    }}




void Teclado(unsigned char tecla, int x, int y) //verifica teclas do teclado para direção
{
    switch(tecla)
    {   
        case 'a':
        case 'A':
        {
            playerx = playerx-5;
            direcao = 'a';
            break;
        }
        case 'w':
        case  'W':
        {
            playery = playery+5;
            direcao ='w';
            break;
        }
        case 's':
        case  'S':
        {
            playery = playery-5;
            direcao ='s';
            break;
        }
        case 'd' :
        case  'D':
        {
            playerx = playerx+5;
            direcao ='d';
            break;
        }
        default:
        break;
    }
    glutPostRedisplay();
    }

void Redimensiona(int width, int height) //função fornecida
{
   // left, bottom, right, top
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void Contador( int value) 
{
    glutPostRedisplay();
    glutTimerFunc( 100, Contador, 0 );
    switch(direcao){
        case 'a':
        playerx-=1;
        break;

        case 'd':
        playerx+=1;
        break;

        case 'w':
        playery+=1;
        break;

        case 's':
        playery-=1;
        break;

    default:
    playerx+=1;
    break;
    }
    if(bot_voltar==0){ //movimentação dos bots
        bot+=8;
    if(bot>50){
        bot_voltar =1;
        }
    }
    else if (bot_voltar==1){
        bot-=8;
        if (bot<-90){
            bot_voltar =0;
        }
    }

    if(voltarS==0){
        missel+=8;
    if(missel>70){
        voltarS =1;
    }
    }
    else if (voltarS==1){
        missel-=8;
        if (missel<-60){
            voltarS =0;
        }
    }
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("2o projeto - Marcos Paulo");
   glutKeyboardFunc(Teclado);
   glutSpecialFunc(teclasEspeciais);
   glutReshapeFunc(Redimensiona);
   glutDisplayFunc(desenhaMinhaCena);
   glutTimerFunc( 100, Contador, 0 );
   setup();
   glutMainLoop();
   return 0;
}