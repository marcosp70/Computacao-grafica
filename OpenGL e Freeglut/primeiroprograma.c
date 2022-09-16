// Aluno: Marcos Paulo Santos da Silva
// Matrícula: 20203002042
// Disciplina: Computação Gráfica
// 
// Código que redimensiona a tela, identifica o mouse e seu click e
// lê a tecla digitada

#include <GL/glew.h>     
#include <GL/freeglut.h>  
#include <stdio.h>

// callback de desenho (display)
void desenhaMinhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);

    // desenha um POLYGON por seus vértices
    glBegin(GL_POLYGON);
        glVertex3f(20, 20, 0);
        glVertex3f(80, 20, 0);
        glVertex3f(80, 80, 0);
        glVertex3f(20, 80, 0);
    glEnd();
    glFlush();
}

void inicializa() {
    // define qual é a cor do fundo
    glClearColor(1, 1, 1, 1); // branco
}


void redimensionada(int width, int height) {
   glViewport(0, 0, width, height);
   printf("Tamanho da tela: largura:%d -- altura: %d \n\n",width,height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 100, 0, 100, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void printa(unsigned char tecla){
  printf("%c",tecla);
}

void teclaPressionada(unsigned char key, int x, int y) {
    // vê qual tecla foi pressionada
    switch(key) {
    case 27:      // Tecla "ESC"
        printf("Tecla ESC, você fechou a aplicação :(  \n",key);
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        exit(0);  // Sai da aplicação
        
        break;
    default: //outras teclas
    printf("Tecla pressionada:%c  \n",key);
    printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    }
}

void teclasEspeciais(int key, int x, int y) {
    switch (key){//teclas especiais (CTRL, ALT E SHIFT não estão inclusas pois a biblioteca freeglut_std.h não as considera como keys, e sim como activates para um combo com outros botões)
    case GLUT_KEY_F1:
        printf("Tecla pressionada: F1 function key.\n");
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break; 
    case GLUT_KEY_F2:
        printf("Tecla pressionada: F2 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F3:
        printf("Tecla pressionada: F3 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F4:
        printf("Tecla pressionada: F4 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F5:
        printf("Tecla pressionada: F5 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F6:
        printf("Tecla pressionada: F6 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F7:
        printf("Tecla pressionada: F7 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F8:
        printf("Tecla pressionada: F8 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F9:
        printf("Tecla pressionada: F9 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F10:
        printf("Tecla pressionada: F10 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F11:
        printf("Tecla pressionada: F11 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_F12:
        printf("Tecla pressionada: F12 function key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_LEFT:
        printf("Tecla pressionada: Left directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_UP:
        printf("Tecla pressionada: Up directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_RIGHT:
        printf("Tecla pressionada: Right directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_DOWN:
        printf("Tecla pressionada: Down directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_PAGE_UP:
        printf("Tecla pressionada: Page up directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_PAGE_DOWN:
        printf("Tecla pressionada: Page down directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_HOME:
        printf("Tecla pressionada: Home directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_END:
        printf("Tecla pressionada: End directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    case GLUT_KEY_INSERT:
        printf("Tecla pressionada: Insert directional key.\n"); 
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    default:
        printf("Tecla pressionada:%d  \n",key);
        printf("Posição do mouse: x = %d y = %d\n\n",x,y);
        break;
    }}

// Função callback chamada para gerenciar eventos do mouse
void gerenciaMouse(int button, int state, int x, int y)
{

    printf("Posição: x = %d -- y = %d\n\n",x,y);

    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
            printf("O botão esquerdo do mouse se encontra pressionado\n");
            printf("Posição quando ocorreu o clique: x = %d -- y = %d\n\n",x,y);
         }
         else{
            printf("O botão esquerdo do mouse foi solto\n");
            printf("Posição quando ocorreu o clique: x = %d -- y = %d\n\n",x,y);}
    if (button == GLUT_RIGHT_BUTTON){
         if (state == GLUT_DOWN) {
            printf("O botão direito do mouse se encontra pressionado\n");
            printf("Posição quando ocorreu o clique: x = %d -- y = %d\n\n",x,y);
         }
         else{
            printf("O botão direito do mouse foi solto\n");
            printf("Posição quando ocorreu o clique: x = %d -- y = %d\n\n",x,y);}}
    glutPostRedisplay();
}

void movimentaMouse(int x, int y){ //função para coletar os movimentos do mouse
    printf("Posição: x = %d -- y = %d\n\n",x,y);
}

// função principal
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Hello World");

   // registra callbacks para alguns eventos
   glutDisplayFunc(desenhaMinhaCena);
   glutReshapeFunc(redimensionada);  
   glutKeyboardFunc(teclaPressionada);
   glutSpecialFunc(teclasEspeciais);
   glutMouseFunc(gerenciaMouse);
   glutPassiveMotionFunc(movimentaMouse);
   inicializa();

   glutMainLoop();
   return 0;
}