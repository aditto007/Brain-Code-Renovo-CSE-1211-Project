#include<bits/stdc++.h>
#include "iGraphics.h"
#include <string.h>
#include <stdbool.h>
#include<ctype.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
//Home and Level 3 flags
int home=1;
int level1 = 0; // if it is set to one level 1 will display
int level3=0;
int level2=0;

char str[300], str2[300], encrypt[300]; // for storing the input
char entry[300];
int len = 0;
int mode = 1; // level 2 round 1 is mode 1 
int levels=0 ;// all level page
bool musicon=true;
int flagmusic=1;
int instruction =0;
int flag_go=0;
//Level 1 Flags
int flag1=0;
int flag2=0;
int flag3=0;
int flag4=0;
int flag5=0;
int flag6=0;
int flag7=0;
int flag8=0;
int flag9=0;
int a=0;
int b=0;
int c=0;
char iq1[20]={ "iq\\1.bmp" };
char iq2[20]={ "iq\\2.bmp" };
char iq3[20]={ "iq\\3.bmp" };
char over[20]={ "iq\\5.bmp" };
char correct[20]={ "iq\\4.bmp" };
char levelup[20]={ "iq\\6.bmp" };
char score00[20]={"iq\\7.bmp"};
char score10[20]={"iq\\8.bmp"};
char score20[20]={"iq\\9.bmp"};
char score30[20]={"iq\\10.bmp"};
char score40[20]={"iq\\11.bmp"};
char score50[20]={"iq\\12.bmp"};
char score60[20]={"iq\\13.bmp"};
char score70[20]={"iq\\14.bmp"};
char score80[20]={"iq\\15.bmp"};
char score90[20]={"iq\\16.bmp"};
char score100[20]={"iq\\17.bmp"};
int level1page1=0;
 
 //Level 02 flags(shafahid)

char background[20] = "im\\Background.bmp";
char gameover[20] = "im\\Game_over.bmp";
void game2();
void game2mouse(int button,int state,int mx,int my);
void round_one(); // shows the first round
void round_one_letter(); // matches the letter with answer
void round_one_move(int button,int state,int mx,int my); // takes input string
void round_two();// shows the second round
void round_two_letter(); // matches the letter with answer
void round_two_move(int button,int state,int mx,int my);
void round_three(); // shows the three
void round_three_letter(); // matches the letter with answer
void round_three_move(int button,int state,int mx,int my); // takes input string
void wrong_answer_click_2(int button,int state,int mx,int my);
void wrong_answer_click_3(int button,int state,int mx,int my);
bool round1 = 1;// checks if it is round one
bool round2 = 0;// checks if it is round two
bool round3 = 0;// checks if it is round three
char point[100]; // stores score
string s1[20] = {""};  //  HOT
string s2[20] = {""};  // LIGHT
string s3[20] = {""}; // LIFE  
char A[20] = {"im\\Aa.bmp"};
char B[20] = {"im\\Bb.bmp"};
char H[20] = {"im\\Hh.bmp"};
char O[20] = {"im\\Oo.bmp"};
char S[20] = {"im\\Ss.bmp"};
char T[20] = {"im\\Tt.bmp"};
char E[20] = {"im\\Ee.bmp"};
char R[20] = {"im\\Rr.bmp"};
char F[20] = {"im\\ff.bmp"};
char sr[20] = {"im\\black.bmp"};
char L[20] = {"im\\Ll.bmp"};
char G[20] = {"im\\Gg.bmp"};
char I[20] = {"im\\Ii.bmp"};
char Life[20] = {"im\\life.bmp"};
char hot[20] = {"im\\hot.bmp"};
char Light[20] = {"im\\light.bmp"};
char cor[20]={"iq\\4.bmp"};


int score = 30;
char Alphabets[30][30] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
int r1letter1=0,r1letter2=0,r1letter3=0; // flags for each letter in round one
int r1letter1_id =-1,r1letter2_id =-1,r1letter3_id =-1; // stores index for each letter in round one
int r2letter1=0,r2letter2=0,r2letter3=0,r2letter4=0,r2letter5=0; // flags for each letter in round two
int r2letter1_id =-1,r2letter2_id =-1,r2letter3_id =-1,r2letter4_id =-1,r2letter5_id =-1; // stores index for each letter in round two
int r3letter1=0,r3letter2=0,r3letter3=0,r3letter4=0; // flags for each letter in round three
int r3letter1_id =-1,r3letter2_id =-1,r3letter3_id =-1,r3letter4_id=-1; // // stores index for each letter in round three
string  ans1 = "HOT";
string ans2 = "LIGHT";
string ans3 = "LIFE";
int get1 = 0; // flag to start round two
int get2 = 0; // flag to start round three
int get3 = 0; // flag to start next round
int flag11=0;
int flag12=0;
int enter1=0;
int enter2=0;
int enter3=0;
void game2_1keyboard(unsigned char key);
void game2_2keyboard(unsigned char key);
void game2_3keyboard(unsigned char key);



// Function prototypes
void alllevels();// alllevels
void alllevelsmouse (int button,int state,int mx,int my);

 
void game3(); // declaring for whole level 3



void game2keyboard(unsigned char key); // controlling keyboard
void cipher(char *text, int key); // encrpyting declaration
void game3imouse(int button,int state,int mx,int my);// controlling mouse event for level 2
void homepagemouse(int button,int state,int mx,int my);//controlling mouse event for homepage
void instructionmouse(int button,int state,int mx,int my);// controlling mouse event for instruction page
void game1();//declaring for whole game
void game1mouse(int button,int state,int mx,int my);//controlling mouse event for level 1
void game1keyboard(unsigned char key);
void game3keyboard(unsigned char key);
void playClickSound() {
    mciSendString("open \"click.wav\" type waveaudio alias click", NULL, 0, NULL);
    mciSendString("play click from 0", NULL, 0, NULL);
}
void rerun_click(int button,int state,int mx,int my);


// Main Idraw function

void iDraw()
{   
    if(home==1)
    {
        iShowBMP2(0,0,"homepage\\menu.bmp",0);
        level1=0;
        level2=0;
        level3=0;
        flag1=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;
        flag6=0;
        flag7=0;
        flag8=0;
        flag9=0;
        flag11=0;
        flag12=0;
        a=0;
        round1=1;
        round2=0;
        round3=0;
        get1=0;
        get2=0;
        get3=0;
        enter1=0;
        enter2=0;
        enter3=0;
        score=30;
        c=0;
        
    }
    if(instruction==1)
    {
        iShowBMP2(0,0,"homepage\\instruction.bmp",0);
    }
    
    if(levels ==1)
    {
       alllevels();
    }
    if(level1==1)
    {
        game1();
        level1page1=1;
        
    }
     if(level2==1){
        game2();
    }
    // Gameover for level 2 starts
    if(flag_go==3){
        iShowBMP(0,0,score30);
        
    }
    if(flag_go==4){
        iShowBMP(0,0,score40);
        
    }
    if(flag_go==5){
        iShowBMP(0,0,score50);
       
    }
    // Game over for level 2 ends
    if(level3==1)
    {
        game3();
    }

           
// All mouse and keyboard functions for homepage and other levels starts    
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{          
          if(home==1)
        {
            homepagemouse(button,state,mx,my);   
        }
          if(instruction==1)
        {
            instructionmouse(button,state,mx,my);
        }
        
          if(levels==1)
        {
            alllevelsmouse(button,state,mx,my);
        }
          if(level1==1)
        {
            game1mouse(button,state,mx,my);
        }
           if(level2==1){
            game2mouse(button,state,mx,my);
        }
    if(level2==2){
    
          if(level3==1)
          {
            game3imouse(button,state,mx,my);
          }
        }    

}
  


void iKeyboard(unsigned char key)
{   
    if(level1 ==1)
    {
        game1keyboard(key);
    }
   
     if(level2 ==1)
    {
       game2keyboard(key);
    }
     if(level3==1)
    {
        game3keyboard(key);
    }
     if(level2 ==1)
    { 
          if(enter1){
        game2_1keyboard(key);
    }
       if(enter2){
        game2_2keyboard(key);
    }
    if(enter3){
        game2_3keyboard(key);
    }
    }
}

void iSpecialKeyboard(unsigned char key)
{
}

void alllevels()
{
    iShowBMP2(0,0,"all levels.bmp",0);
}

void game1keyboard(unsigned char key)
{
    if(key=='y')
    {
        level1=0;
        level1page1=0;
        home=1;

    }
}
void game2keyboard(unsigned char key)
{
    if(key=='z')
    {
        level2=0;
        
        home=1;

    }
}
void game2_1keyboard(unsigned char key){
        if(key=='\r'){
            flag11=1;
            score=40;

        }
}

void game2_2keyboard(unsigned char key){
    if(key=='\r'){
        flag11=2;
        score=50;
    }
}

void game2_3keyboard(unsigned char key){
    if(key=='\r'){
        flag11 = 3;
    }
} 

void alllevelsmouse(int button,int state,int mx,int my)
{
       if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
       { 
            
          
          if(levels==1 && (mx>=124 && mx <= 444) && (my>=325&&my<=399))
          {
            level1=1;
            levels=0;
             playClickSound();
          }
          if(levels==1 && (mx>=116 &&mx<=458) && (my>=189 && my<=263))
          {  
             playClickSound();
             level2=1;
             levels=0;
          }
          if(levels==1 && (mx>=116 && mx <=452) && (my>=62 && my<=140))
          {
            level3=1;
            levels=0;
            level2=2;
            playClickSound();
          }
          if(levels==1 && (mx>=119 && mx<=218) && (my>=453 && my<=558))
          {
            home=1;
            levels=0;
            playClickSound();
          }
          printf("x:%d y:%d\n",mx,my);
       }

}
void homepagemouse(int button,int state,int mx,int my)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(home==1 &&(mx>=752&& mx<=959)&& (my>=239&&my<=274))
        {
            levels=1;;
            home=0;
            playClickSound();
        }
        if(home==1 &&(mx>=751 &&mx<=963)&&(my>=147 &&my<=197))
        {
            instruction=1;
            home=0;
            playClickSound();
        }
        if(home==1 &&(mx>=750 && mx<=959)&&(my>=70 && my<=120))
        {
            //scoreboard
            playClickSound();
        }
        
       
    }
}
// All Mouse and Keyboard function for Homepage and other levels ends

// Level 1 Starts(Aditto)
void game1()
{
    if(level1page1==1){
    iShowBMP(0,0,iq1);
    iSetColor(255,255,255);
    iText(900,50,"SCORE:0",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(flag1)
    {
        iShowBMP(0,0,correct);
        a=1;
    }
    if(flag2)
    {
        iShowBMP(0,0,score00);
        c=1;
       
    }
    if(flag3)
    {
        iShowBMP(0,0,iq2);
        a=2;
        iSetColor(255,255,255);
        iText(900,50,"SCORE:10",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(flag4)
    {
        iShowBMP(0,0,correct);
        a=3;
    }
    if(flag5)
    {
        iShowBMP(0,0,score10);
        c=2;
    }
    if(flag6)
    {
        iShowBMP(0,0,iq3);
        a=5;
        iSetColor(255,255,255);
        iText(900,50,"SCORE:20",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(flag7)
    {
        iShowBMP(0,0,levelup);
        a=6;
    }
    if(flag8)
    {
        iShowBMP(0,0,score30);
        c=3;   
    }
}

void game1mouse(int button,int state,int mx,int my)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if((mx>=330&&mx<=445&&my>=56&&my<=144)&&flag2!=1){
			flag1=1;//iq level 1 correct answer
            playClickSound();
           
		}
		if((mx>=448&&mx<=688&&my>=56&&my<=236)||(mx>=330&&mx<=445&&my>=145&&my<=233)&&a==0){
			flag2=1;
            playClickSound();    //level 1 game over
		}
		if((mx>=0&&mx<=1024&&my>=0&&my<=600)&&a==1) 
        {
            flag3=1;//iq level 2 appear
            playClickSound();
        }
		if((mx>=379&&mx<=451&&my>=89&&my<=161)&&a==2) 
        {
            flag4=1; //iq level 02 correct answer
            playClickSound();
        }
		if((mx>=275&&mx<=347&&my>=89&&my<=161)||(mx>=485&&mx<=557&&my>=89&&my<=161)||(mx>=591&&mx<=663&&my>=89&&my<=161)||(mx>=695&&mx<=767&&my>=89&&my<=161)){ 
        if(a==2)    
        {
            flag5=1; //iq level 02 game over
            playClickSound();
        }
        }

		if((mx>=0&&mx<=1024&&my>=0&&my<=600)&&a==3) 
        {
            flag6=1;//iq level 3 appear
            playClickSound();
        }
		if((mx>=633&&mx<=748&&my>=54&&my<=169)&&a==5) 
        {
            flag7=1; //iq level 03 correct answer
            playClickSound();
        }
		if((mx>=279&&mx<=631&&my>=54&&my<=169)&&a==5) 
        {
            flag8=1; //iq level 03 gameover
        }
        if((mx>=0&&mx<=1024&&my>=0&&my<=600)&&a==6)
        {
            level1=0;
            level2=1; ;
        }
        if(c==1&&a==0) rerun_click(button,state,mx,my);
        if(c==2&&a==2) rerun_click(button,state,mx,my);	
        if(c==3&&a==4) rerun_click(button,state,mx,my);		
    }
}
// Level 2 Starts(Shafahid)
void round_one(){
    iShowBMP2(100,200,A,0); iShowBMP2(180,200,B,0);
    iShowBMP2(260,200,H,0); iShowBMP2(340,200,O,0);
    iShowBMP2(100,100,S,0); iShowBMP2(180,100,T,0);
    iShowBMP2(260,100,E,0); iShowBMP2(340,100,R,0);
    iShowBMP2(600,266,hot,0);
    //All level 2 round 1 images
}
void round_two(){
    iShowBMP2(100,200,A,0); iShowBMP2(180,200,B,0);
    iShowBMP2(340,100,R,0); iShowBMP2(260,200,H,0);
    iShowBMP2(180,100,T,0); iShowBMP2(260,100,L,0);
    iShowBMP2(340,200,G,0); iShowBMP2(100,100,I,0);
    iShowBMP2(577,266,Light,0);
    //All level 2 round 2 images
}
void round_three(){
    iShowBMP2(100,200,A,0); iShowBMP2(180,200,B,0);
    iShowBMP2(260,200,F,0); iShowBMP2(340,200,O,0);
    iShowBMP2(100,100,S,0); iShowBMP2(180,100,L,0);
    iShowBMP2(260,100,E,0); iShowBMP2(340,100,I,0);
    iShowBMP2(600,300,Life,0);
    //All level 2 round 3 images
}
void round_one_letter(){ // prints output & result for level 2 round 1
    if(r1letter1){
        iText(808,100,Alphabets[r1letter1_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //686 
    }
    if(r1letter2){
        iText(828,100,Alphabets[r1letter2_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //706
    }
    if(r1letter3){
        iText(850,100,Alphabets[r1letter3_id],GLUT_BITMAP_TIMES_ROMAN_24);
        // 728
    }
    if(s1[0].size()==ans1.size()){
        if(s1[0][0]==ans1[0]&&s1[0][1]==ans1[1]&&s1[0][2]==ans1[2]){
        enter1 =1;
           if(flag11){
    iShowBMP(0,0,cor);
    get1=1;
   }
        
        }
        else{
        iText(220,320,"WRONG ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get3 = 1;
        }
    }
}
void round_two_letter(){ // prints output & result for level 2 round 2
    if(r2letter1){
        iText(808,100,Alphabets[r2letter1_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //686
    }
    if(r2letter2){
        iText(828,100,Alphabets[r2letter2_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //706
    }
    if(r2letter3){
        iText(844,100,Alphabets[r2letter3_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //722
    }
    if(r2letter4){
        iText(867,100,Alphabets[r2letter4_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //745
    }
    if(r2letter5){
        iText(888,100,Alphabets[r2letter5_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //766
    }
    if(s2[0].size()==ans2.size()){
        if(s2[0][0]==ans2[0]&&s2[0][1]==ans2[1]&&s2[0][2]==ans2[2]&&s2[0][3]==ans2[3]&&s2[0][4]==ans2[4]){
        enter2=1;
           if(flag11==2){
    iShowBMP(0,0,cor);
    get2=1;
   }
        }
        else{
        iText(220,320,"WRONG ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get3 = 2;
        }
        }
}
void round_three_letter(){ // prints output & result for level 2 round 3
    if(r3letter1){
        iText(808,100,Alphabets[r3letter1_id],GLUT_BITMAP_TIMES_ROMAN_24);
        // 686
    }
    if(r3letter2){
        iText(828,100,Alphabets[r3letter2_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //706
    }
    if(r3letter3){
        iText(848,100,Alphabets[r3letter3_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //720
    }
    if(r3letter4){
        iText(868,100,Alphabets[r3letter4_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //736
    }
    if(s3[0].size()==ans3.size()){
        if(s3[0][0]==ans3[0]&&s3[0][1]==ans3[1]&&s3[0][2]==ans3[2]&&s3[0][3]==ans3[3]){
        enter3=1;
           if(flag11==3){
    iShowBMP(0,0,levelup);
    flag12=1;
    
   }
        }
        else{
        iText(220,320,"WRONG ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get3 = 3;
        }
    }
} 
void round_one_move(int button,int state,int mx,int my){
if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>100&&mx<180&&my>=200&&my<=280){
            // for A
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'a'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'a'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'a'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }
            playClickSound();
        }else if(mx>260&&mx<340&&my>=200&&my<=280){
            // for H
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'h' - 'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'h' - 'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'h' - 'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }
           playClickSound(); 
        }else if(mx>340&&mx<420&&my>=200&&my<=280){
            // for O
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'o'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'o'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'o'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            } 
            playClickSound();  
        }else if(mx>180&&mx<260&&my>=100&&my<=180){
            // for T
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 't'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 't'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 't'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }
            playClickSound();   
        }else if(mx>340&&mx<420&&my>=100&&my<=180){
            // for R
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'r'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'r'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'r'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }  
            playClickSound(); 
        }else if(mx>100&&mx<=180&&my>=100&&my<=180){
            // for S
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 's'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 's'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 's'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
        }else if(mx>260&&mx<340&&my>100&&my<160){
            // for E
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'e'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'e'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'e'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }
            playClickSound();   
        }else if(mx>180&&mx<260&&my>=200&&my<=280){
            // for B
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'b'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'b'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'b'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
            playClickSound();
        }
    }
}
void round_one_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user after round one
            round1 = 0;
            round2 = 1;
            playClickSound();
        }
        
    }
}
void round_two_move(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>100&&mx<180&&my>=200&&my<=280){
            // for A
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }else if(mx>260&&mx<340&&my>=200&&my<=280){
             // for H
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }else if(mx>180&&mx<260&&my>=200&&my<=280){
            // for B
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }else if(mx>180&&mx<260&&my>=100&&my<=180){
            // for T
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }else if(mx>340&&mx<420&&my>=100&&my<=180){
            //For R
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }else if(mx>260&&mx<340&&my>100&&my<160){
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }else if(mx>340&&mx<420&&my>=200&&my<=280){
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }else if(mx>100&&mx<=180&&my>=100&&my<=180){
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
            playClickSound();
        }
    }
}
void round_two_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user after round two
            round2 = 0; 
            round3 = 1;
            playClickSound();
        }
    }
}
void round_three_move(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>100&&mx<180&&my>=200&&my<=280){
            // for A
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }
            playClickSound();
        }else if(mx>260&&mx<340&&my>=200&&my<=280){
            // for F
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'f' - 'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'f' - 'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'f' - 'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'f'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }
            playClickSound();
        }else if(mx>340&&mx<420&&my>=200&&my<=280){
            // for O
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            } 
            playClickSound();  
        }else if(mx>180&&mx<260&&my>=100&&my<=180){
            // for L
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            } 
            playClickSound();  
        }else if(mx>340&&mx<420&&my>=100&&my<=180){
            // for I
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            } 
            playClickSound();  
        }else if(mx>100&&mx<=180&&my>=100&&my<=180){
            // for S
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }  
            playClickSound(); 
        }else if(mx>260&&mx<340&&my>100&&my<160){
            // for E
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }  
            playClickSound(); 
        }else if(mx>180&&mx<260&&my>=200&&my<=280){
            // for B
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            } 
            playClickSound();  
        }
    }
}
// FUnctions for level 2 wrong answers
void wrong_answer_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user if the answer is wrong
        flag_go=3;
        playClickSound();
        }

    }
}
void wrong_answer_click_2(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user if the answer is wrong
        flag_go=4;
        playClickSound();
        }
    }
}
void wrong_answer_click_3(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user if the answer is wrong
        flag_go=5;
        playClickSound();
        }
    }
}
void game2(){
    iShowBMP(0,0,"im\\Background.bmp");
    iShowBMP2(788,80,sr,0);
    iText(900,50,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(point,"%d",score);
    iText(986,50,point,GLUT_BITMAP_TIMES_ROMAN_24);
    
    if(round1){
        round_one();
        round_one_letter();
    }
    if(round2){
        get1 = 0;
        round_two();
        round_two_letter();
    }
    if(round3){
        get2 = 0;
        round_three();
        round_three_letter();
    }
}
void levelup_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user after round two
            level2=2 ;
            level3=1;
        }
    }
}

void game2mouse(int button,int state,int mx,int my){
if(round1){
        round_one_move(button,state,mx,my);
    }
    if(get1){
        round_one_click(button,state,mx,my);
    }
    if(round2){
        round_two_move(button,state,mx,my);
    }
    if(get2){
        round_two_click(button,state,mx,my);
    }
    if(round3){
        round_three_move(button,state,mx,my);
    }
    if(get3==1){
        wrong_answer_click(button,state,mx,my);
    }
    if(get3==2){
        wrong_answer_click_2(button,state,mx,my);
    }
    if(get3==3){
        wrong_answer_click_3(button,state,mx,my);
    }
    if(flag12==1)
        {
          levelup_click(button,state,mx,my);  
        }	
}


//Level 2 ends
// Level 3 Starts
void cipher(char *text, int key) // encrypting the text
{
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            encrypt[i] = 'a' + (text[i] - 'a' + key) % 26;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            encrypt[i] = 'A' + (text[i] - 'A' + key) % 26;
        }
    }
    encrypt[i]='\0';
}
void game3()
{
    if (mode == 1)  // The beginning screen will appear
    {   
        
        
        iShowBMP2(0, 0, "round 2 images\\level2-1.bmp", 0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 1",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92, 64, 51);
        iText(500, 275, str, GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(900,50,"SCORE:60",GLUT_BITMAP_TIMES_ROMAN_24);
          // the user input show in brown color
    }
    else if (mode == 2)
    {
        iSetColor(255, 255, 255); // activate for showing encrpt message for round 1
        iText(480, 220, encrypt, GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,180,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=3; // update to go to next page
        
        
    }
    else if (flag_go == 6) // wrong answer game over show round 1
    {
        iShowBMP2(0, 0,score60, 0);
    }
    else if (flag_go == 7) // wrong answer game over show round 2
    {
        iShowBMP2(0, 0,score70, 0);
    }
    else if (flag_go == 8) // wrong answer game over show round 3
    {
        iShowBMP2(0, 0,score80, 0);
    }
    else if (flag_go == 9) // wrong answer game over show round 4
    {
        iShowBMP2(0, 0,score90, 0);
    }
    else if(mode==4) //round 2 begin and showing user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-2.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 2",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,275,str,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(900,50,"SCORE:70",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(mode==5) //round 2 encrypt text
    {
        iSetColor(255,255,255);
        iText(480,220,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,180,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=6;

    }
    else if(mode==7)// round 3 begin answer && user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-3.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 3",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,220,str,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(900,50,"SCORE:80",GLUT_BITMAP_TIMES_ROMAN_24);
        
    }
    else if(mode==8) //round 3 encrypt text
    {
        iSetColor(255,255,255);
        iText(480,180,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,130,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=9;
    }
    else if(mode==10) //round 4 begin image && user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-4.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 4",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,220,str,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(900,50,"SCORE:90",GLUT_BITMAP_TIMES_ROMAN_24);
        
    }
    else if(mode==11) // round 4  encrypt text
    {    
        iSetColor(255,255,255);
        iText(480,180,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,130,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
       
        mode=12;
    }
    else if(mode==13){
        iShowBMP(0,0,score100);
        b=1;
    }
    
}
void game3keyboard(unsigned char key)
{
    int i;
	if(mode == 1) // round 1 user input
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
            if(strcmp(str,"12")==0)
            {
                 cipher("gibgvwbs",12);
                 mode=2;
            }
            else
            {
                flag_go=6;
            }
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
        else if(key=='\b') //backspace key
        {
            if(len>0)
            {
                len--;
                str[len]='\0';
            }
        }
		else
		{
			str[len] = key;
			len++;
		}
    }
    if(mode==4) // round 2 user input
    {
        if(key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            if(strcmp(str,"6")==0)
            {
                cipher("pifuncfy",6);
                mode=5;
            }
            else 
            {
                flag_go=7;
            }
            printf("%s\n",str2);
            for(i=0;i<len;i++)
            str[i]=0;
            len=0;
        }
        else if(key=='\b')
        {
            len--;
            str[len]='\0';
        }
        else
        {
            str[len]=key;
            len++;
        }
    }
    
    if(mode==7) // round 3 user input
    {
        if(key=='\r')
        {
            
            strcpy(str2,str);
        
         if(strcmp(str,"3")==0) 
         {
            cipher("bkbodv",3);
            mode=8;
         }
         else
         {
            flag_go=8;
         }
         printf("%s\n",str);
         for(i=0;i<len;i++) 
         str[i]=0;
         len=0;
        }
        else if(key=='\b')
        {
            len--;
            str[len]='\0';
        }
        else
        {
            str[len]=key;
            len++;
        }
    }
     if(mode==10) // round 4 user input
     {
        if(key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            if(strcmp(str,"2")==0)
            {
                cipher("bcapwnr",2);
                mode=11;
            }
            else
            {
                flag_go=9;
            }
            for(i=0;i<len;i++)
            str[i]=0;
            len=0;
        }
        else if(key=='\b')
        {
            len--;
            str[len]='\0';
        }
        else
        {
            str[len]=key;
            len++;
        }
     }
     if(key=='x')
     {
        level3=0;
        
        home=1;
        mode=1;
        for(i=0;i<len;i++)
        {
            str[i]=0;
            len=0;
        }
     } // for exiting game


    
        
}

            

void game3imouse(int button,int state,int mx,int my)
{
       if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
       {
        if(mode==3)
        {   
            mode=4;
            playClickSound();
            
        }
        else if(mode==6)
        {   
            playClickSound();
            mode=7;
        }
       else  if(mode==9)
        {   
            playClickSound();
            mode=10;
        }
      else if(mode==12)
      {
        playClickSound();
        mode=13;
      }
      else if(b==1&&(mx>=0&&mx<=1024&&my>=0&&my<=600)){
        level3=0;
        home=1;
      }

       } 
       
} 
void instructionmouse(int button,int state,int mx,int my)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(instruction==1 &&(mx>=757&&mx<=960)&&(my>=45&&my<=132))
        {
            instruction=0;
            home=1;
            playClickSound();
        }
    }
}
void rerun_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user after round two
            home=1;
        }
    }
}




    

        
int main()
{   
     if(musicon&&flagmusic==1)
     {
     PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
     
     }
     iInitialize(1024,600,"Brain Code: Renovo");
    return 0;
}
    
        
       
        
        
        
       



    
    
    
        
    
        
        




    
        
        
    
        
    
   
    