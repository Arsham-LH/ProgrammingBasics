#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include<ctime>
#include<windows.h>
#include<fstream>
#include<SDL2/SDL_mixer.h>
// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com


//MOHAMMAD HOSEIN FARAMARZI - ARSHAM LOLOHARI


using namespace std;

void loadbrick_1(SDL_Renderer *m_renderer , int x_start , int y_start)
{
    SDL_Texture *brick_img;
    brick_img=IMG_LoadTexture(m_renderer , "blue bricks.jpg");
    int brickw,brickh;
    SDL_QueryTexture(brick_img , NULL , NULL , &brickw , &brickh);
    SDL_Rect dest_brickrect;
    dest_brickrect.x=x_start;
    dest_brickrect.y=y_start;
    dest_brickrect.w=175;
    dest_brickrect.h=50;
    SDL_Rect src_brickrect;
    src_brickrect.x=7;
    src_brickrect.y=7;
    src_brickrect.w=150;
    src_brickrect.h=60;
    SDL_RenderCopy(m_renderer , brick_img , &src_brickrect , &dest_brickrect);
    SDL_RenderPresent(m_renderer);
}
//                    rect(m_renderer , xstart_board , ystart_board , board_width , board_height , 255 , 255 , 0 , 1);


void loadboard(SDL_Renderer *m_renderer , SDL_Texture *boardTexture , int xstart_board , int ystart_board , int board_width , int board_height)
{

    SDL_Rect srcrect;
    srcrect.x = 60 ;
    srcrect.y = 10 ;
    srcrect.w = board_width ;
    srcrect.h = board_height ;

    SDL_Rect dstrect ;
    dstrect.x = xstart_board ;
    dstrect.y = ystart_board ;
    dstrect.w = board_width ;
    dstrect.h = board_height ;

    SDL_RenderCopy(m_renderer , boardTexture , &srcrect , &dstrect ) ;

}

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;


    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
//    SDL_RenderPresent(Renderer);

}

void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian)
{
    if(fill_boolian==1)
        filledEllipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);
    if(fill_boolian==0)
        ellipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);
    SDL_RenderPresent(Renderer);
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );
    SDL_RenderClear( Renderer );

    // Show the window
    SDL_RenderPresent( Renderer );

}

void update_bottom_text(SDL_Renderer *m_renderer , SDL_Texture *brick_n_text_Texture , SDL_Texture *wallpaperTexture, int xlevel , int xscore , int xlives , int xdamage , int ytext , string levelshow , string scoreshow , string livesshow , string damageshow , int font , int font_size)
{
//    SDL_Rect bottom_text_blank ;
//
//    bottom_text_blank.x = xlevel-5 ;
//    bottom_text_blank.y = ytext-3 ;
//    bottom_text_blank.w = 1200 ;
//    bottom_text_blank.h = 100 ;

    SDL_SetRenderTarget(m_renderer , brick_n_text_Texture);

//    SDL_RenderCopy(m_renderer , wallpaperTexture , &bottom_text_blank , &bottom_text_blank);

    textRGBA(m_renderer , xlevel , ytext , levelshow.c_str() , font , font_size , 255 , 0 , 0 , 255);
    textRGBA(m_renderer , xscore , ytext , scoreshow.c_str() , font , font_size , 255 , 0 , 0 , 255);
    textRGBA(m_renderer , xlives , ytext , livesshow.c_str() , font , font_size , 255 , 0 , 0 , 255);
    textRGBA(m_renderer , xdamage , ytext , damageshow.c_str() , font , font_size , 255 , 0 , 0 , 255);

    SDL_SetRenderTarget(m_renderer , NULL);

}

void destroy_brick(SDL_Renderer *m_renderer , SDL_Texture *brick_n_text_Texture , SDL_Texture *wallpaperTexture , int i , int j , int last_bricks_row , int last_bricks_column , int strength[20][8] , int x_start_brick[8] , int y_start_brick[20] , int brick_w , int brick_h , int horizon_bricks_dist , int vertic_bricks_dist)
{
    SDL_SetRenderTarget(m_renderer , brick_n_text_Texture);
    SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);

    string strengthshow;

    int tmp_i , tmp_j ;
    for (tmp_i=last_bricks_row ; tmp_i>=0 ; tmp_i--)
    {
        for (tmp_j=0 ; tmp_j<=last_bricks_column ; tmp_j++)
        {
            if ((tmp_j!=j || tmp_i!=i) && (strength[tmp_i][tmp_j]!=0))
            {
                rect(m_renderer , x_start_brick[tmp_j] , y_start_brick[tmp_i] , brick_w , brick_h , strength[tmp_i][tmp_j] * 10 , 20 , strength[tmp_i][tmp_j] * 50 , 1);

                if (strength[tmp_i][tmp_j]<=9)
                {
                    strengthshow=char(strength[tmp_i][tmp_j])+'0' ;
                }
                else if (strength[tmp_i][tmp_j]>9 && strength[tmp_i][tmp_j]<=99)
                {
                    char strength_left_digit=char (strength[tmp_i][tmp_j]/10)+'0' , strength_right_digit=char (strength[tmp_i][tmp_j]%10)+'0' ;
                    strengthshow=strength_left_digit;
                    strengthshow+=strength_right_digit;
                }

                textRGBA(m_renderer , x_start_brick[tmp_j]+brick_w/2 , y_start_brick[tmp_i]+brick_h/2 , strengthshow.c_str() , 2 , 20 , 0 , 255 , 0 , 255 );

            }
        }
    }
    SDL_SetRenderTarget(m_renderer , NULL);
}

void add_brick_row(SDL_Renderer *m_renderer , SDL_Texture *brick_n_text_Texture , SDL_Texture *wallpaperTexture , int last_bricks_row , int last_bricks_column , int strength[20][8] , int x_start_brick[8] , int y_start_brick[20] , int brick_w , int brick_h , int level , int vertic_bricks_dist)
{
    SDL_SetRenderTarget(m_renderer , brick_n_text_Texture);
    SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);
    string strengthshow;
    int tmp_i , tmp_j ;

    for (tmp_i=last_bricks_row ; tmp_i>=1 ; tmp_i--)
    {
        y_start_brick[tmp_i]=tmp_i*brick_h+(tmp_i+1)*vertic_bricks_dist;

        for (tmp_j=0 ; tmp_j<=last_bricks_column ; tmp_j++)
        {
            strength[tmp_i][tmp_j]=strength[tmp_i-1][tmp_j];
            if (strength[tmp_i][tmp_j]!=0)
            {
            rect(m_renderer , x_start_brick[tmp_j] , y_start_brick[tmp_i] , brick_w , brick_h , strength[tmp_i][tmp_j] * 10 , 20 , strength[tmp_i][tmp_j] * 50 , 1);

            if (strength[tmp_i][tmp_j]<=9)
            {
                strengthshow=char(strength[tmp_i][tmp_j])+'0';
            }
            else if (strength[tmp_i][tmp_j]>9 && strength[tmp_i][tmp_j]<=99)
            {
                char strength_left_digit=char (strength[tmp_i][tmp_j]/10)+'0' , strength_right_digit=char (strength[tmp_i][tmp_j]%10)+'0' ;
                strengthshow=strength_left_digit;
                strengthshow+=strength_right_digit;
            }

            cout<<" "<<strengthshow;

            textRGBA(m_renderer , x_start_brick[tmp_j]+brick_w/2 , y_start_brick[tmp_i]+brick_h/2 , strengthshow.c_str() , 2 , 20 , 0 , 255 , 0 , 255 );
            }
            cout<<endl;
        }
    }

    int number_of_0_strengths=0 ;

    for (tmp_j=0 ; tmp_j<=last_bricks_column ; tmp_j++)
    {
        strength[0][tmp_j]=rand()%(level+1) ;

        if (number_of_0_strengths>=8/4)
        {
            strength[0][tmp_j]=(rand()%(level))+1;
        }

        if (strength[0][tmp_j]==0)
        {
            number_of_0_strengths++;
        }

        if (tmp_j == last_bricks_column && number_of_0_strengths ==0)
        {
            strength[0][rand()%last_bricks_column+1]=0 ;
        }
    }
    for (tmp_j=0 ; tmp_j<=last_bricks_column ; tmp_j++)
    {
        if (strength[0][tmp_j]!=0)
        {
            rect(m_renderer , x_start_brick[tmp_j] , y_start_brick[0] , brick_w , brick_h , strength[0][tmp_j] * 10 , 20 , strength[tmp_i][tmp_j] * 50 , 1);

            if (strength[tmp_i][tmp_j]<=9)
            {
                strengthshow=char(strength[tmp_i][tmp_j])+'0';
            }
            else if (strength[tmp_i][tmp_j]>9 && strength[tmp_i][tmp_j]<=99)
            {
                char strength_left_digit=char (strength[tmp_i][tmp_j]/10)+'0' , strength_right_digit=char (strength[tmp_i][tmp_j]%10)+'0' ;
                strengthshow=strength_left_digit;
                strengthshow+=strength_right_digit;
            }

            textRGBA(m_renderer , x_start_brick[tmp_j]+brick_w/2 , y_start_brick[0]+brick_h/2 , strengthshow.c_str() , 2 , 20 , 0 , 255 , 0 , 255 );

        }
    }
    SDL_SetRenderTarget(m_renderer , NULL);
}

int random_sign()
{
    int a=rand()%2;
    if (a==1)
        a=1;
    else if (a==0)
        a=-1;
    return a;
}

void pause (SDL_Event *pause)
{
    SDL_PollEvent(pause) ;
    if (pause->type == SDL_KEYDOWN && pause->key.keysym.sym == SDLK_p)
    {

        pause->type = 0 ;
        SDL_PollEvent(pause) ;
        while ((pause->type != SDL_KEYDOWN) || (pause->type == SDL_KEYDOWN && pause->key.keysym.sym != SDLK_p && pause->key.keysym.sym != SDLK_ESCAPE ))
        {
            SDL_Delay(1) ;
            SDL_PollEvent(pause) ;
        }
    }
}

string choosemap(SDL_Renderer *menu , int window_W , int window_H , SDL_Event *e_menu )
{
    SDL_SetRenderDrawColor(menu , 0 , 0 , 0 , 255) ;
    SDL_RenderClear(menu);

    string game_map="map " ;
    string choosemap="ENTER THE NUMBER OF YOUR MAP FROM 1 TO 9 :" ;
    textRGBA(menu , window_W/2-600 , window_H/2 , choosemap.c_str() , 2 , 50 , 50 , 20 , 255 , 255 ) ;



    SDL_PollEvent(e_menu);


    while (((e_menu->type!=SDL_KEYDOWN)))
        SDL_PollEvent(e_menu);
            switch (e_menu->key.keysym.sym)
            {
            case SDLK_1:
                game_map+="1.jpg";
                break;
            case SDLK_2:
                game_map+="2.jpg";
                break;
            case SDLK_3:
                game_map+="3.jpg";
                break;
            case SDLK_4:
                game_map+="4.jpg";
                break;
            case SDLK_5:
                game_map+="5.jpg";
                break;
            case SDLK_6:
                game_map+="6.jpg";
                break;
            case SDLK_7:
                game_map+="7.jpg";
                break;
            case SDLK_8:
                game_map+="8.jpg";
                break;
            case SDLK_9:
                game_map+="9.jpg";
                break;
            }
        return game_map ;

}

int main( int argc, char * argv[] )
{

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music *backgroundSound = Mix_LoadMUS("game.mp3");
    Mix_Music *menu_backgroundSound = Mix_LoadMUS("menu.mp3");

    int n , number_of_histories=0;
    srand(time(NULL));
//    cout<<"Enter n:";
//    cin>>n;
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP ;//SDL_WINDOW_BORDERLESS ; /* resolution :1536*864*/
    SDL_Window * m_window ;
    SDL_Renderer * m_renderer ;
    SDL_Renderer * menu ;





    SDL_CreateWindowAndRenderer( 1200 , 800 , WND_flags , &m_window , &menu );
    SDL_SetRenderDrawColor(menu , 0 , 0 , 0 ,255) ;
    SDL_RenderClear(menu) ;

    Mix_PlayMusic(menu_backgroundSound,-1);    // Show the window
//Texture for loading image

    SDL_Texture *wallpaperTexture;
    SDL_Texture *brick_n_text_Texture;
    SDL_Texture *boardTexture;

    SDL_Texture *nameTexture ;
    SDL_Texture *new_or_load_Texture ;





    SDL_Init( SDL_flags );


    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int window_W = DM.w;
    int window_H = DM.h;
    cout<<window_W<<" "<<window_H ;
    // Clear the window with a black background

    nameTexture = SDL_CreateTexture( menu , SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , window_W, window_H );


















































    int /*dx_board=15 ,*/ board_width=167 , board_height=20 , xstart_board=window_W/2-board_width/2 , ystart_board=window_H-60 , xgame_board=xstart_board , board_corners_w=40;

    int r_ball=13;

    int  horizon_bricks_dist=3*r_ball , vertic_bricks_dist=2*r_ball , brick_corners_w=25 , brick_corners_h=5 , brick_w=(window_W-9*horizon_bricks_dist)/8 , brick_h=45 ;



    int i , j , x_start_brick[8] , y_start_brick[20] , strength[20][8] , last_bricks_row=2 , last_bricks_column=7 ;

    for (i=0 ; i<=last_bricks_row ; i++)
    {
        for (j=0 ; j<=last_bricks_column ; j++)
        {
            strength[i][j]=1 ;
        }
    }

    string strength_digit;

    string levelshow = "level : 1";
    string scoreshow ="score : 0";
    string livesshow = "lives : 3";
    string damageshow = "damage : 1";



    int level=1 , damage=level , score=0 , lives=3 , scoreshow_length=scoreshow.length() , lives_length = livesshow.length() , levelshow_length=levelshow.length() , damageshow_length=damageshow.length() ;

    int ascii_code_0=48;

    int xlevel=window_W/2-400 , xscore=window_W/2-200 , xlives=window_W/2+200 , xdamage=window_W/2+400 , ytext=window_H-40 , font=2 , font_size=40 ;
















    new_or_load_Texture = SDL_CreateTexture( menu , SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , window_W , window_H );

    SDL_SetRenderTarget(menu , nameTexture) ;

    string name_text = "PLEASE ENTER YOUR NAME : ";
    textRGBA(menu , window_W/2-250 , window_H/2 , name_text.c_str() , 2 , 40 , 0 , 255 , 255 , 255);

    SDL_SetRenderTarget(menu , NULL) ;

    SDL_RenderCopy(menu , nameTexture , NULL , NULL);

    rect(menu , window_W/2-200 , window_H/2+90 , 500 , 100 , 255 , 0 , 0 , 0);

    SDL_RenderPresent(menu);

    string name=" ";
    string game_map="map ";
    int name_length=1 ;



    SDL_Event *e_menu=new SDL_Event ;

    while (((e_menu->type!=SDL_KEYDOWN) || (e_menu->type==SDL_KEYDOWN && e_menu->key.keysym.sym !=SDLK_SPACE))/*&&(quit==false)*/)
    {
        SDL_PollEvent(e_menu);

        if (e_menu->type==SDL_KEYDOWN)
        {
            switch (e_menu->key.keysym.sym)
            {
                case SDLK_a :
                    name+='a';
                    cout<<endl<<name;
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_b :
                    name+='b';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_c :
                    name+='c';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_d :
                    name+='d';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_e :
                    name+='e';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_f :
                    name+='f';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_g :
                    name+='g';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_h :
                    name+='h';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_i :
                    name+='i';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_j :
                    name+='j';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_k :
                    name+='k';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_l :
                    name+='l';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_m :
                    name+='m';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_n :
                    name+='n';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_o :
                    name+='o';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_p :
                    name+='p';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_q :
                    name+='q';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_r :
                    name+='r';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_s :
                    name+='s';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_t :
                    name+='t';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_u :
                    name+='u';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_v :
                    name+='v';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_w :
                    name+='w';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_x :
                    name+='x';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_y :
                    name+='y';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++;
                    break ;
                case SDLK_z :
                    name+='z';
                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;
                    name_length++ ;
                    break ;
//                case SDLK_SPACE :
//                    name+=' ';
//                    name_length++;
//                    break;

                case SDLK_BACKSPACE :
                    name=name.substr(0,name_length-1) ;

                    name_length-- ;

                    SDL_RenderCopy(menu , nameTexture , NULL , NULL) ;

                    rect(menu , window_W/2-200 , window_H/2+90 , 500 , 100 , 255 , 0 , 0 , 0) ;

                    textRGBA(menu , window_W/2-175 , window_H/2+100 , name.c_str() , 2 , 30 , 0 , 0 , 255 , 255) ;

                    SDL_RenderPresent(menu);

                    e_menu->type=0 ;
                    break ;


            }
        }
    }


    ifstream load ;
    ofstream save ;
    string name_history=name ;
    name_history+="_history_1" ;
    load.open(name_history.c_str()) ;
    if (load.good())
    {
        load.close();
        SDL_SetRenderDrawColor(menu , 0 , 0 , 0 , 255) ;
        SDL_RenderClear(menu) ;

        string history_1="YOUR LAST 5(OR FEWER) GAMES HISTORY :" , history_2="PRESS ANY KEY TO CONTINUE" ;
        int xstart_history_1 = window_W/2-600 , xstart_history_2 = window_W/2-250 , ystart_history_1 = 70 , ystart_history_2 = window_H-75 , history_1_fontsize = 60 , history_2_fontsize = 30 ;

        textRGBA(menu , xstart_history_1 , ystart_history_1 , history_1.c_str() , 2 , history_1_fontsize , 0 , 255 , 255 , 255);
        textRGBA(menu , xstart_history_2 , ystart_history_2 , history_2.c_str() , 2 , history_2_fontsize , 0 , 255 , 255 , 255);


        int rects_w=400 , rects_h=50 , xstart_rects=window_W/2-rects_w/2 , ystart_rect[5] ;

        for (int g=1 ; g<=5 ; g++)
        {
            string name_history = name+"_history_";

            char number_of_history = char (g) +ascii_code_0 ;

            ystart_rect[g] = 100*g+150 ;

            name_history+=number_of_history ;

            cout<<endl<<name_history<<endl;

            load.open(name_history.c_str()) ;

            if (load.good())
            {
                cout<<"good"<<endl;
                rect(menu , xstart_rects , ystart_rect[g] , rects_w , rects_h , 255 , 0 , 0 , 0);

                int file_level_save , file_score_save , file_lives_save ;
                string file_levelshow_save="level : 0" , file_scoreshow_save="score : 0" , file_livesshow_save="lives : 0" ;

                load>>file_level_save>>file_score_save>>file_lives_save;

                cout<<file_level_save<<endl<<file_score_save<<endl<<file_lives_save<<endl;

                int file_levelshow_save_length=file_levelshow_save.length() , file_scoreshow_save_length=file_scoreshow_save.length() , file_livesshow_save_length=file_livesshow_save.length() ;


                if (file_level_save<=9)
                {
                    file_levelshow_save[file_levelshow_save_length-1]=char (file_level_save)+ascii_code_0 ;
                }
                else
                {
                    char file_level_save_left_digit = char (file_level_save/10)+ascii_code_0 , file_level_save_right_digit = char (file_level_save%10)+ascii_code_0 ;
                    file_levelshow_save="level : 0";
                    file_levelshow_save[file_levelshow_save_length-1]=file_level_save_left_digit;
                    file_levelshow_save+=file_level_save_right_digit;
                }

                cout<<file_levelshow_save <<endl;

                textRGBA(menu , xstart_rects+15 , ystart_rect[g]+15 , file_levelshow_save.c_str() , 2 , 25 , 20 , 255 , 20 , 255);






                if (file_score_save<=9)
                {
                    file_scoreshow_save[file_scoreshow_save_length-1] = char(file_score_save)+ascii_code_0 ;
                }
                else if ((file_score_save>=10) && (file_score_save<=99))
                {
                    file_scoreshow_save="score : 0" ;
                    char file_score_save_right_digit=char (file_score_save%10)+ascii_code_0 , file_score_save_left_digit=char (file_score_save/10)+ascii_code_0 ;
                    file_scoreshow_save[file_scoreshow_save_length-1]=file_score_save_left_digit ;
                    file_scoreshow_save+=file_score_save_right_digit ;
                }
                else if ((file_score_save>=100) && (file_score_save<=999))
                {
                    file_scoreshow_save="score : 0" ;
                    char file_score_save_right_digit=char (file_score_save%10)+ascii_code_0 , file_score_save_mid_digit=char ((file_score_save/10)%10)+ascii_code_0 , file_score_save_left_digit = char (file_score_save/100)+ascii_code_0 ;
                    file_scoreshow_save[file_scoreshow_save_length-1]=file_score_save_left_digit ;
                    file_scoreshow_save+=file_score_save_mid_digit ;
                    file_scoreshow_save+=file_score_save_right_digit ;
                }
                else
                {
                    file_scoreshow_save = "score : 0" ;
                    char file_score_save_1st_digit = char (file_score_save/1000) + ascii_code_0 , file_score_save_2nd_digit = char ((file_score_save/100)%10) + ascii_code_0 , file_score_save_3rd_digit = char((file_score_save/10)%10) + ascii_code_0 , file_score_save_4th_digit = char (file_score_save%10) + ascii_code_0 ;
                    file_scoreshow_save[file_scoreshow_save_length-1] = file_score_save_1st_digit ;
                    file_scoreshow_save+=file_score_save_2nd_digit ;
                    file_scoreshow_save+=file_score_save_3rd_digit ;
                    file_scoreshow_save+=file_score_save_4th_digit ;
                }

                textRGBA(menu , xstart_rects+115 , ystart_rect[g]+15 , file_scoreshow_save.c_str() , 2 , 25 , 20 , 255 , 20 , 255);





                if (file_lives_save>=10)
                {
                    char file_lives_save_left_digit = char (file_lives_save/10)+ascii_code_0 , file_lives_save_right_digit = char (file_lives_save%10)+ascii_code_0 ;
                    file_livesshow_save[file_livesshow_save_length-1]=file_lives_save_left_digit ;
                    file_livesshow_save+=file_lives_save_right_digit ;
                }
                else if (file_lives_save<=9 && file_lives_save>0)
                {
                    file_livesshow_save = "lives : 3" ;

                    file_livesshow_save[file_livesshow_save_length-1]=char (file_lives_save)+ascii_code_0 ;

                }
                else if (file_lives_save ==0)
                {
                    file_livesshow_save = "lives : 0" ;
                }

                textRGBA(menu , xstart_rects+255 , ystart_rect[g]+15 , file_livesshow_save.c_str() , 2 , 25 , 20 , 255 , 20 , 255) ;


                load.close();

            }
            load.close();
        }

        SDL_RenderPresent(menu);

        e_menu->type=0 ;
        while (e_menu->type!=SDL_KEYDOWN)
            SDL_PollEvent(e_menu) ;

    }


    load.open(name.c_str()) ;
    if(load.good())
    {
        SDL_SetRenderDrawColor(menu , 0 , 0 , 0 , 255) ;
        SDL_RenderClear(menu) ;
        string new_out="START A NEW GAME" ;
        int xstart_new_out=window_W/2-200 , fontsize_new_out=50 , ystart_new_out=window_H/2-200 ;

        string load_out="LOAD THE LAST GAME" ;
        int xstart_load_out=window_W/2-220 , fontsize_load_out=50 , ystart_load_out=window_H/2+200 ;

        SDL_SetRenderTarget(menu , new_or_load_Texture) ;

        textRGBA(menu , xstart_new_out , ystart_new_out , new_out.c_str() , 2 , fontsize_new_out , 50 , 255 , 255 , 50) ;
        textRGBA(menu , xstart_load_out , ystart_load_out , load_out.c_str() , 2 , fontsize_load_out , 50 , 255 , 255 , 50) ;

        SDL_SetRenderTarget(menu , NULL) ;

        SDL_RenderCopy(menu , new_or_load_Texture , NULL , NULL) ;

        SDL_RenderPresent(menu) ;

        while(e_menu->type!=SDL_MOUSEBUTTONDOWN)
        {
            SDL_PollEvent(e_menu) ;
            POINT mouse ;
            GetCursorPos(&mouse) ;

            if (mouse.x>=xstart_new_out && mouse.x<=xstart_new_out+495 && mouse.y>=ystart_new_out && mouse.y<=ystart_new_out+50)
            {
                SDL_SetRenderDrawColor(menu , 0 , 0 , 0 , 255) ;
                SDL_RenderClear(menu) ;

                textRGBA(menu , xstart_new_out , ystart_new_out , new_out.c_str() , 2 , fontsize_new_out , 50 , 255 , 255 , 255) ;
//                textRGBA(menu , xstart_load_out , ystart_load_out , load_out.c_str() , 2 , fontsize_load_out , 50 , 255 , 255 , 50);

            }
            else if (mouse.x>=xstart_load_out && mouse.x<=xstart_load_out+560 && mouse.y>=ystart_load_out && mouse.y<=ystart_load_out+50)
            {
                SDL_SetRenderDrawColor(menu , 0 , 0 , 0 , 255) ;
                SDL_RenderClear(menu) ;

//                textRGBA(menu , xstart_new_out , ystart_new_out , new_out.c_str() , 2 , fontsize_new_out , 50 , 255 , 255 , 50);
                textRGBA(menu , xstart_load_out , ystart_load_out , load_out.c_str() , 2 , fontsize_load_out , 50 , 255 , 255 , 255) ;
            }
            else
            {
                SDL_RenderCopy(menu , new_or_load_Texture , NULL , NULL) ;
                SDL_RenderPresent(menu) ;
            }
        }


        POINT mouse ;
        GetCursorPos(&mouse) ;

        if (mouse.x>=xstart_load_out && mouse.x<=xstart_load_out+560 && mouse.y>=ystart_load_out && mouse.y<=ystart_load_out+50)
        {

            int file_level , file_score , file_lives , file_damage , file_last_bricks_row , file_last_bricks_column=7 , file_strength[20][8] ;

            int file_i , file_j ;
//            string file_lives ;

            load>>file_level>>file_score>>file_lives>>file_damage>>file_last_bricks_row ;

            level = file_level ;
            score = file_score ;
            lives = file_lives ;
            damage = file_damage ;
            last_bricks_row = file_last_bricks_row ;

            cout<<endl<<file_level<<" "<<file_score<<" "<<file_lives<<" "<<file_damage<<" "<<file_last_bricks_row<<endl;
            for (file_i=file_last_bricks_row ; file_i>=0 ; file_i--)
            {
                for (file_j=0 ; file_j<=file_last_bricks_column ; file_j++)
                {
                    load>>file_strength[file_i][file_j];

                    strength[file_i][file_j] = file_strength[file_i][file_j];

                    cout<<strength[file_i][file_j]<<" ";

                }
                cout<<endl;
            }



            levelshow = "level : 1";

            if (level<=9)
            {
                levelshow[levelshow_length-1]=char (level)+ascii_code_0 ;
            }
            else
            {
                char level_left_digit = char (level/10)+ascii_code_0 , level_right_digit = char (level%10)+ascii_code_0 ;
                levelshow="level : 0";
                levelshow[levelshow_length-1]=level_left_digit;
                levelshow+=level_right_digit;
            }
            cout<<levelshow<<endl;




            scoreshow ="score : 0";

            if (score<=9)
            {
                scoreshow[scoreshow_length-1] = char(score)+ascii_code_0 ;
            }
            else if ((score>=10) && (score<=99))
            {
                scoreshow="score : 0" ;
                char score_right_digit=char (score%10)+ascii_code_0 , score_left_digit=char (score/10)+ascii_code_0 ;
                scoreshow[scoreshow_length-1]=score_left_digit ;
                scoreshow+=score_right_digit ;
            }
            else if ((score>=100) && (score<=999))
            {
                scoreshow="score : 0" ;
                char score_right_digit=char (score%10)+ascii_code_0 , score_mid_digit=char ((score/10)%10)+ascii_code_0 , score_left_digit = char (score/100)+ascii_code_0 ;
                scoreshow[scoreshow_length-1]=score_left_digit ;
                scoreshow+=score_mid_digit ;
                scoreshow+=score_right_digit ;
            }
            else
            {
                scoreshow = "score : 0" ;
                char score_1st_digit = char (score/1000) + ascii_code_0 , score_2nd_digit = char ((score/100)%10) + ascii_code_0 , score_3rd_digit = char((score/10)%10) + ascii_code_0 , score_4th_digit = char (score%10) + ascii_code_0 ;
                scoreshow[scoreshow_length-1] = score_1st_digit ;
                scoreshow+=score_2nd_digit ;
                scoreshow+=score_3rd_digit ;
                scoreshow+=score_4th_digit ;
            }
            cout<<scoreshow<<endl ;


            if (lives>=10)
            {
                char lives_left_digit = char (lives/10)+ascii_code_0 , lives_right_digit = char (lives%10)+ascii_code_0 ;
                livesshow[lives_length-1]=lives_left_digit ;
                livesshow+=lives_right_digit ;
            }
            else if (lives<=9 && lives>0)
            {
                livesshow = "lives : 3" ;

                livesshow[lives_length-1]=char (lives)+ascii_code_0 ;

            }

            cout<<livesshow<<endl;










            damageshow = "damage : 1" ;

            if (damage<=9)
            {
                damageshow = "damage : 1" ;
                damageshow[damageshow_length-1] = char (damage+ascii_code_0) ;
            }
            else
            {
                damageshow = "damage : 1" ;

                char damage_left_digit = char (damage/10)+ascii_code_0 , damage_right_digit = char (damage%10)+ascii_code_0 ;

                damageshow[damageshow_length-1] = damage_left_digit ;
                damageshow+=damage_right_digit ;
            }
            cout<<damageshow<<endl;

        }
//        load.close() ;
    }
    load.close();
    game_map=choosemap(menu , window_W , window_H , e_menu) ;

















    SDL_DestroyRenderer( menu );















    SDL_CreateWindowAndRenderer( 1920, 1080, WND_flags, &m_window, &m_renderer );
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 ) ;
    SDL_RenderClear( m_renderer );

    Mix_PlayMusic(backgroundSound,-1);    // Show the window
    wallpaperTexture = SDL_CreateTexture( m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , window_W, window_H );

    brick_n_text_Texture = SDL_CreateTexture( m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , window_W, window_H );

    boardTexture = SDL_CreateTexture( m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , window_W, window_H );


    boardTexture=IMG_LoadTexture(m_renderer , "board.jpg");

    int boardw , boardh ;
    SDL_QueryTexture(boardTexture , NULL , NULL , &boardw , &boardh) ;

//    SDL_RenderPresent( m_renderer ) ;


    wallpaperTexture=IMG_LoadTexture(m_renderer , game_map.c_str());
    int wallw,wallh;
    SDL_QueryTexture(wallpaperTexture , NULL , NULL , &wallw , &wallh);

    SDL_SetRenderTarget(m_renderer , brick_n_text_Texture);

    SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);

    for (i=0;i<=last_bricks_row;i++)
    {
        y_start_brick[i]=i*brick_h+(i+1)*vertic_bricks_dist;
        for (j=0;j<=last_bricks_column;j++)
        {
            x_start_brick[j]=j*brick_w+(j+1)*horizon_bricks_dist;

            if (strength[i][j]!=0)
            {
                rect(m_renderer , x_start_brick[j] , y_start_brick[i] , brick_w , brick_h , strength[i][j] * 10 , 20 , strength[i][j] * 50 , 1);

                if (strength[i][j]<=9)
                    strength_digit=char(strength[i][j])+'0';

                else
                {
                    char strength_left_digit = char (strength[i][j]/10)+ascii_code_0 , strength_right_digit = char (strength[i][j]%10)+ascii_code_0 ;
                    strength_digit = "0" ;
                    strength_digit[strength_digit.length()-1]=strength_left_digit ;
                    strength_digit+=strength_right_digit ;
                }

                textRGBA(m_renderer , x_start_brick[j]+brick_w/2 , y_start_brick[i]+brick_h/2 , strength_digit.c_str() , 2 , 20 , 0 , 255 , 0 , 255 );
    //            rect(m_renderer , j*brick_w+(j+1)*horizon_bricks_dist , i*brick_h+(i+1)*vertic_bricks_dist , brick_w , brick_h , 25 , 0 , 255 , 1);
            }
        }
    }

    SDL_SetRenderTarget(m_renderer , NULL);






    update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);

    SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL);

    loadboard(m_renderer , boardTexture , xstart_board , ystart_board , board_width , board_height) ;

    filledEllipseRGBA(m_renderer , xstart_board+board_width/2 , ystart_board-r_ball , r_ball , r_ball ,0,200,0,255);

    SDL_RenderPresent(m_renderer);


    SDL_Event *e = new SDL_Event();

    bool start_game=false;
    while (start_game==false){
        SDL_PollEvent(e);
        if (e->type==SDL_KEYDOWN && e->key.keysym.sym == SDLK_SPACE)
        {
            start_game = true ;
            xgame_board = xstart_board ;
        }
        POINT mouse ;
        GetCursorPos(&mouse) ;
        xstart_board=mouse.x-board_width/2 ;
//        else if (e->type==SDL_MOUSEMOTION)
//        {
//            if (e->motion.x<=window_W && e->motion.x>=0)
//            xstart_board=e->motion.x;
//        }


//        if (e->type==SDL_KEYDOWN)
//        {
//            switch(e->key.keysym.sym)
//            {
//                case SDLK_a:
//                    if (xstart_board>=0)
//                    xstart_board-=dx_board;
//                    break;
//                case SDLK_d:
//                    if (xstart_board+board_width<=window_W)
//                    xstart_board+=dx_board;
//                    break;
//                case SDLK_SPACE:
//                    start_game=true;
//                    xgame_board=xstart_board;
//                    break;
//            }
//
            int xstart_ball=xstart_board+board_width/2 , ystart_ball=ystart_board-r_ball ;

//            SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);


//            SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);

            SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL) ;


            loadboard(m_renderer , boardTexture , xstart_board , ystart_board , board_width , board_height) ;

            filledEllipseRGBA(m_renderer , xstart_ball , ystart_ball , r_ball , r_ball , 0 , 200 , 0 , 255);

            SDL_RenderPresent(m_renderer) ;
//        }
    }
    SDL_PollEvent(e);
    double xstart_ball=xstart_board+board_width/2 , ystart_ball=ystart_board-r_ball ;
    double tmp_dx_ball=(rand()%17)+4 , tmp_dy_ball=(rand()%17)+30 , dx_ball , dy_ball ;
    tmp_dx_ball/=10;
    tmp_dy_ball/=10;
    dx_ball=random_sign()*tmp_dx_ball;
    dy_ball=tmp_dy_ball;

    double const_V=sqrt(dx_ball*dx_ball+dy_ball*dy_ball);

    cout<<"const_V 1: "<<const_V<<endl;

    bool gameover=false;

    while (((e->type!=SDL_KEYDOWN) || (e->type==SDL_KEYDOWN && e->key.keysym.sym!=SDLK_ESCAPE)) && (gameover==false))
    {
        pause(e) ;
//        SDL_Delay(20);
        double xend_ball=xstart_ball , yend_ball=ystart_ball ;
        xstart_ball+=dx_ball ;
        ystart_ball-=dy_ball ;
//        xend_ball=xstart_ball ;
//        yend_ball=ystart_ball;
        if (xend_ball+r_ball>=window_W)
        {

            dx_ball=-1*tmp_dx_ball ;
            cout<<endl<<"dx_ball 2 : "<<dx_ball<<endl;
        }
        if (xend_ball-r_ball<=0)
        {

            dx_ball=1*tmp_dx_ball;
            cout<<endl<<"dx_ball 2 : "<<dx_ball<<endl;
        }
        if (yend_ball+r_ball>=window_H)
        {

            dy_ball=1*tmp_dy_ball;
            cout<<endl<<"dx_ball 2 : "<<dx_ball<<endl;
        }
        if (yend_ball-r_ball<=0 /*|| yend_ball-r_ball<=y_start_brick[i]+brick_h*/)
        {

            dy_ball=-1*tmp_dy_ball;
            cout<<endl<<"dx_ball 2 : "<<dx_ball<<endl;
        }
        if ((( yend_ball+r_ball>=ystart_board) && (xend_ball-r_ball<=xgame_board+board_width && xend_ball+r_ball>=xgame_board)))
        {

            dy_ball=1*tmp_dy_ball;
            cout<<endl<<"dx_ball 2 : "<<dx_ball<<endl;
        }
        if ((yend_ball+r_ball>=ystart_board) && (xend_ball-r_ball<=xgame_board+board_width && xend_ball-r_ball>=xgame_board+board_width-board_corners_w))
        {
            double tmp_dy_ball=(rand()%17)+30;
            if (tmp_dy_ball/10>=0.75*const_V)
            {
                tmp_dy_ball=7.5*const_V;
            }

            tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball);

            tmp_dy_ball/=10 ;
            tmp_dx_ball/=10 ;

            dx_ball=1*tmp_dx_ball;
            dy_ball=1*tmp_dy_ball;

            cout<<endl<<"dx_ball 1 : "<<dx_ball<<endl;
            cout<<"const_V 2 : "<<sqrt(dx_ball*dx_ball+dy_ball*dy_ball)<<endl;
            cout<<"\ntmp_dy_ball : "<<tmp_dy_ball<<" & dy_ball : "<<dy_ball;
        }
        else if ((yend_ball+r_ball>=ystart_board) && (xend_ball+r_ball>=xgame_board && xend_ball+r_ball<=xgame_board+board_corners_w))
        {
            double tmp_dy_ball=(rand()%17)+30 ;

            if (tmp_dy_ball/10>=0.75*const_V)
            {
                tmp_dy_ball=7.5*const_V ;
            }

            tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball) ;

            tmp_dy_ball/=10 ;
            tmp_dx_ball/=10 ;

            dx_ball=-1*tmp_dx_ball ;
            dy_ball=1*tmp_dy_ball ;

            cout<<endl<<"dx_ball 1 : "<<dx_ball<<endl ;
            cout<<"const_V 2 : "<<sqrt(dx_ball*dx_ball+dy_ball*dy_ball)<<endl ;
            cout<<"\ntmp_dy_ball :"<<tmp_dy_ball<<" & dy_ball : "<<dy_ball ;
        }
        if (yend_ball>ystart_board)
        {
            lives-- ;
            int lives_length = livesshow.length() ;
            if (lives>=10)
            {
                char lives_left_digit = char (lives/10)+ascii_code_0 , lives_right_digit = char (lives%10)+ascii_code_0 ;
                livesshow[lives_length-1]=lives_left_digit ;
                livesshow+=lives_right_digit ;
            }
            else if (lives<=9 && lives>0)
            {
                livesshow = "lives : 3" ;

                livesshow[lives_length-1]=char (lives)+ascii_code_0 ;

                destroy_brick(m_renderer , brick_n_text_Texture , wallpaperTexture , -1 , -1 , last_bricks_row , last_bricks_column , strength , x_start_brick , y_start_brick , brick_w , brick_h , horizon_bricks_dist , vertic_bricks_dist ) ;

                update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);

            }
            else if (lives==0)
            {
                livesshow = "lives : 0" ;

                destroy_brick(m_renderer , brick_n_text_Texture , wallpaperTexture , -1 , -1 , last_bricks_row , last_bricks_column , strength , x_start_brick , y_start_brick , brick_w , brick_h , horizon_bricks_dist , vertic_bricks_dist ) ;

                update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);

                gameover = true ;
            }
            if (lives!=0)
            {
                filledEllipseRGBA(m_renderer , xend_ball , yend_ball , r_ball+3 , r_ball+3 , 0 , 0 , 0 , 255) ;

                xstart_board = xgame_board ;
                yend_ball = ystart_board - r_ball ;
                ystart_ball = ystart_board - r_ball ;
                xend_ball = xstart_board + board_width/2 ;
                xstart_ball = xstart_board + board_width/2 ;

                filledEllipseRGBA(m_renderer , xstart_ball , ystart_ball , r_ball , r_ball , 0 , 200 , 0 , 255) ;

                SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL) ;

                loadboard(m_renderer , boardTexture , xstart_board , ystart_board , board_width , board_height) ;

                filledEllipseRGBA(m_renderer , xstart_ball , ystart_ball , r_ball , r_ball , 0 , 200 , 0 , 255) ;


                SDL_RenderPresent(m_renderer) ;

                /*tmp_dx_ball=(rand()%17)+4 ,*/ tmp_dy_ball=(rand()%17)+30 , dx_ball , dy_ball ;
                if (tmp_dy_ball/10>=0.75*const_V)
                {
                    tmp_dy_ball=7.5*const_V;
                }
                tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball);

                tmp_dx_ball/=10 ;
                tmp_dy_ball/=10 ;

                dx_ball=random_sign()*tmp_dx_ball ;
                dy_ball=tmp_dy_ball ;

                scoreshow="score :  " ;

                bool start_game=false ;
                while (start_game==false)
                {
                    SDL_PollEvent(e) ;

                    if (e->type==SDL_KEYDOWN && e->key.keysym.sym == SDLK_SPACE)
                    {
                        start_game=true ;
                        xgame_board=xstart_board ;
                    }
                    POINT mouse ;
                    GetCursorPos(&mouse) ;
                    xstart_board=mouse.x-board_width/2 ;

//                    if (e->type==SDL_KEYDOWN)
//                    {
//                        switch(e->key.keysym.sym)
//                        {
//                            case SDLK_a:
//                                if (xstart_board>=0)
//                                xstart_board-=dx_board;
//                                break;
//                            case SDLK_d:
//                                if (xstart_board+board_width<=window_W)
//                                xstart_board+=dx_board;
//                                break;
//                            case SDLK_SPACE:
//                                start_game=true;
//                                xgame_board=xstart_board;
//                                break;
//                        }

                        xstart_ball=xstart_board+board_width/2 , ystart_ball=ystart_board-r_ball;

                        SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);

                        SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL);

                        loadboard(m_renderer , boardTexture , xstart_board , ystart_board , board_width , board_height) ;

                        filledEllipseRGBA(m_renderer , xstart_ball , ystart_ball , r_ball , r_ball , 0 , 200 , 0 , 255);

                        SDL_RenderPresent(m_renderer);
//                    }
                }
                xstart_ball=xstart_board+board_width/2 ;
                ystart_ball=ystart_board-r_ball ;
            }
        }
        for (i=last_bricks_row ; i>=0 ; i--)
        {
            for (j=0;j<8;j++)
            {
                pause(e) ;

                if (((xend_ball-r_ball<x_start_brick[j]+brick_w && xend_ball-r_ball>x_start_brick[j]) || (xend_ball+r_ball>x_start_brick[j] && xend_ball+r_ball<x_start_brick[j]+brick_w)) && (yend_ball-r_ball<=y_start_brick[i]+brick_h) && (yend_ball>=y_start_brick[i]+brick_h) && (dy_ball>0) && (strength[i][j]>0))
                {

                    int tmp_damage=damage ;
                    damage-=strength[i][j] ;

                    strength[i][j]-=tmp_damage ;
                    if (strength[i][j]<=0)
                    {
                        strength[i][j]=0 ;
                        score+=level ;
                        if (score<=9)
                        {
                            scoreshow[scoreshow_length-1] = char(score+ascii_code_0) ;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , ytext , levelshow , scoreshow , lives , font , font_size);
                        }
                        else if ((score>=10) && (score<=99))
                        {
                            scoreshow="score : 0" ;
                            char score_right_digit=char (score%10)+ascii_code_0 , score_left_digit=char (score/10)+ascii_code_0 ;
                            scoreshow[scoreshow_length-1]=score_left_digit ;
                            scoreshow+=score_right_digit ;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        else if ((score>=100) && (score<=999))
                        {
                            scoreshow="score : 0" ;
                            char score_right_digit=char (score%10)+ascii_code_0 , score_mid_digit=char ((score/10)%10)+ascii_code_0 , score_left_digit = char (score/100)+ascii_code_0 ;
                            scoreshow[scoreshow_length-1]=score_left_digit ;
                            scoreshow+=score_mid_digit ;
                            scoreshow+=score_right_digit ;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        else
                        {
                            scoreshow = "score : 0" ;
                            char score_1st_digit = char (score/1000) + ascii_code_0 , score_2nd_digit = char ((score/100)%10) + ascii_code_0 , score_3rd_digit = char((score/10)%10) + ascii_code_0 , score_4th_digit = char (score%10) + ascii_code_0 ;
                            scoreshow[scoreshow_length-1] = score_1st_digit ;
                            scoreshow+=score_2nd_digit ;
                            scoreshow+=score_3rd_digit ;
                            scoreshow+=score_4th_digit ;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        cout<<endl<<"scoreshow : "<<scoreshow ;
                    }
                    if (damage<0)
                        damage=0 ;

                    if (damage<=9)
                    {
                        damageshow = "damage : 1";
                        damageshow[damageshow_length-1] = char (damage+ascii_code_0) ;
                    }
                    else
                    {
                        damageshow = "damage : 1";

                        char damage_left_digit = char (damage/10)+ascii_code_0 , damage_right_digit = char (damage%10)+ascii_code_0 ;

                        damageshow[damageshow_length-1] = damage_left_digit ;
                        damageshow+=damage_right_digit ;
                    }

                    if (xend_ball<=x_start_brick[j]+brick_w-brick_corners_w && xend_ball>=x_start_brick[j]+brick_corners_w)
                    {

                        dy_ball=-1*tmp_dy_ball ;
                    }
                    else
                    {
                        double tmp_dy_ball=(rand()%17)+30 ;

                        if (tmp_dy_ball/10>=0.75*const_V)
                        {
                            tmp_dy_ball=7.5*const_V ;
                        }

                        tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball) ;

                        tmp_dy_ball/=10 ;
                        tmp_dx_ball/=10 ;

                        dx_ball=random_sign()*tmp_dx_ball ;
                        dy_ball=-1*tmp_dy_ball ;
                    }

                        destroy_brick(m_renderer , brick_n_text_Texture , wallpaperTexture , i , j , last_bricks_row , last_bricks_column , strength , x_start_brick , y_start_brick , brick_w , brick_h , horizon_bricks_dist , vertic_bricks_dist ) ;

                        update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);

                }

                else if (((xend_ball-r_ball<x_start_brick[j]+brick_w && xend_ball-r_ball>x_start_brick[j]) || (xend_ball+r_ball>x_start_brick[j] && xend_ball+r_ball<x_start_brick[j]+brick_w)) && (yend_ball+r_ball>=y_start_brick[i]) && (yend_ball<=y_start_brick[i]) && (dy_ball<0) && (strength[i][j]>0))
                {

                    int tmp_damage=damage ;
                    damage-=strength[i][j] ;
                    strength[i][j]-=tmp_damage ;
                    if (strength[i][j]<=0)
                    {
                        strength[i][j]=0 ;
                        score+=level ;
                        if (score<=9)
                        {
                            scoreshow[scoreshow_length-1]=char(score+ascii_code_0) ;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        else if ((score>=10) && (score<=99))
                        {
                            scoreshow="score : 0" ;
                            char score_right_digit=char (score%10)+ascii_code_0 , score_left_digit=char (score/10)+ascii_code_0 ;
                            scoreshow[scoreshow_length-1]=score_left_digit ;
                            scoreshow+=score_right_digit ;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore , xlives , ytext , levelshow , scoreshow , lives , font , font_size);
                        }
                        else
                        {
                            scoreshow="score : 0" ;
                            char score_right_digit=char (score%10)+ascii_code_0 , score_mid_digit=char ((score/10)%10)+ascii_code_0 , score_left_digit = char (score/100)+ascii_code_0 ;
                            scoreshow[scoreshow_length-1]=score_left_digit ;
                            scoreshow+=score_mid_digit ;
                            scoreshow+=score_right_digit ;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        cout<<endl<<"scoreshow : "<<scoreshow ;
                    }
                    if (damage<0)
                        damage=0 ;

                    if (damage<=9)
                    {
                        damageshow = "damage : 1";
                        damageshow[damageshow_length-1] = char (damage+ascii_code_0) ;
                    }
                    else
                    {
                        damageshow = "damage : 1";

                        char damage_left_digit = char (damage/10)+ascii_code_0 , damage_right_digit = char (damage%10)+ascii_code_0 ;

                        damageshow[damageshow_length-1] = damage_left_digit ;
                        damageshow+=damage_right_digit ;
                    }


                    if (xend_ball<=x_start_brick[j]+brick_w-brick_corners_w && xend_ball>=x_start_brick[j]+brick_corners_w)
                    {

                        dy_ball=1*tmp_dy_ball ;
                    }
                    else
                    {
                        double tmp_dy_ball=(rand()%17)+30 ;

                        if (tmp_dy_ball/10>=0.75*const_V)
                        {
                            tmp_dy_ball=7.5*const_V ;
                        }

                        tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball) ;

                        tmp_dy_ball/=10 ;
                        tmp_dx_ball/=10 ;

                        dx_ball=random_sign()*tmp_dx_ball ;
                        dy_ball=1*tmp_dy_ball ;
                    }

                    destroy_brick(m_renderer , brick_n_text_Texture , wallpaperTexture , i , j , last_bricks_row , last_bricks_column , strength , x_start_brick , y_start_brick , brick_w , brick_h , horizon_bricks_dist , vertic_bricks_dist ) ;

                    update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);

                }

                else if ( (xend_ball-r_ball<=x_start_brick[j]+brick_w && xend_ball-r_ball>=x_start_brick[j]) && ((yend_ball+r_ball>=y_start_brick[i] && yend_ball+r_ball<=y_start_brick[i]+brick_h)||(yend_ball-r_ball<=y_start_brick[i]+brick_h && yend_ball-r_ball>=y_start_brick[i])) && (strength[i][j]>0) )
                {

                    int tmp_damage=damage;
                    damage-=strength[i][j];
                    strength[i][j]-=tmp_damage;
                    if (strength[i][j]<=0)
                    {
                        strength[i][j]=0;
                        score+=level;
                        if (score<=9)
                        {
                            scoreshow[scoreshow_length-1]=char(score+ascii_code_0);
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        else if ((score>=10) && (score<=99))
                        {
                            scoreshow="score : 0";
                            char score_right_digit=char (score%10)+ascii_code_0 , score_left_digit=char (score/10)+ascii_code_0;
                            scoreshow[scoreshow_length-1]=score_left_digit;
                            scoreshow+=score_right_digit;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore , xlives , ytext , levelshow , scoreshow , lives , font , font_size);
                        }
                        else
                        {
                            scoreshow="score : 0";
                            char score_right_digit=char (score%10)+ascii_code_0 , score_mid_digit=char ((score/10)%10)+ascii_code_0 , score_left_digit = char (score/100)+ascii_code_0 ;
                            scoreshow[scoreshow_length-1]=score_left_digit;
                            scoreshow+=score_mid_digit;
                            scoreshow+=score_right_digit;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        cout<<endl<<"scoreshow : "<<scoreshow;
                    }
                    if (damage<0)
                        damage=0;

                    if (damage<=9)
                    {
                        damageshow = "damage : 1";
                        damageshow[damageshow_length-1] = char (damage+ascii_code_0) ;
                    }
                    else
                    {
                        damageshow = "damage : 1";

                        char damage_left_digit = char (damage/10)+ascii_code_0 , damage_right_digit = char (damage%10)+ascii_code_0 ;

                        damageshow[damageshow_length-1] = damage_left_digit ;
                        damageshow+=damage_right_digit ;
                    }

                    if (yend_ball<=y_start_brick[i]+brick_h-brick_corners_h && yend_ball>=y_start_brick[i]+brick_corners_h)
                    {

                        dx_ball=1*tmp_dx_ball;
                    }
                    else
                    {
                        double tmp_dy_ball=(rand()%17)+30 ;

                        if (tmp_dy_ball/10>=0.75*const_V)
                        {
                            tmp_dy_ball=7.5*const_V ;
                        }

                        tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball) ;

                        tmp_dy_ball/=10 ;
                        tmp_dx_ball/=10 ;

                        dx_ball=1*tmp_dx_ball ;
                        dy_ball=random_sign()*tmp_dy_ball ;
                    }

                    destroy_brick(m_renderer , brick_n_text_Texture , wallpaperTexture , i , j , last_bricks_row , last_bricks_column , strength , x_start_brick , y_start_brick , brick_w , brick_h , horizon_bricks_dist , vertic_bricks_dist ) ;

                    update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);

                }

                else if ( (xend_ball+r_ball>=x_start_brick[j] && xend_ball+r_ball<=x_start_brick[j]+brick_w) && ((yend_ball+r_ball>=y_start_brick[i] && yend_ball+r_ball<=y_start_brick[i]+brick_h)||(yend_ball-r_ball<=y_start_brick[i]+brick_h && yend_ball-r_ball>=y_start_brick[i])) && (strength[i][j]>0) )
                {

                    int tmp_damage=damage;
                    damage-=strength[i][j];
                    strength[i][j]-=tmp_damage;
                    if (strength[i][j]<=0)
                    {
                        strength[i][j]=0;
                        score+=level;
                        if (score<=9)
                        {
                            scoreshow[scoreshow_length-1]=char(score+ascii_code_0);
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore , xlives , ytext , levelshow , scoreshow , lives , font , font_size);
                        }
                        else if ((score>=10) && (score<=99))
                        {
                            scoreshow="score : 0";
                            char score_right_digit=char (score%10)+ascii_code_0 , score_left_digit=char (score/10)+ascii_code_0;
                            scoreshow[scoreshow_length-1]=score_left_digit;
                            scoreshow+=score_right_digit;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore , xlives , ytext , levelshow , scoreshow , lives , font , font_size);
                        }
                        else
                        {
                            scoreshow="score : 0";
                            char score_right_digit=char (score%10)+ascii_code_0 , score_mid_digit=char ((score/10)%10)+ascii_code_0 , score_left_digit = char (score/100)+ascii_code_0 ;
                            scoreshow[scoreshow_length-1]=score_left_digit;
                            scoreshow+=score_mid_digit;
                            scoreshow+=score_right_digit;
//                            update_bottom_text(m_renderer , brick_n_text_Texture , xlevel , xscore, xlives, ytext, levelshow , scoreshow , lives , font , font_size);
                        }
                        cout<<endl<<"scoreshow : "<<scoreshow;
                    }
                    if (damage<0)
                        damage=0;

                    if (damage<=9)
                    {
                        damageshow = "damage : 1";
                        damageshow[damageshow_length-1] = char (damage+ascii_code_0) ;
                    }
                    else
                    {
                        damageshow = "damage : 1";

                        char damage_left_digit = char (damage/10)+ascii_code_0 , damage_right_digit = char (damage%10)+ascii_code_0 ;

                        damageshow[damageshow_length-1] = damage_left_digit ;
                        damageshow+=damage_right_digit ;
                    }

                    if (yend_ball<=y_start_brick[i]+brick_h-brick_corners_h && xend_ball>=x_start_brick[j]+brick_corners_h)
                    {

                        dx_ball=-1*tmp_dx_ball;
                    }
                    else
                    {
                        double tmp_dy_ball=(rand()%17)+30 ;

                        if (tmp_dy_ball/10>=0.75*const_V)
                        {
                            tmp_dy_ball=7.5*const_V ;
                        }

                        tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball) ;

                        tmp_dy_ball/=10 ;
                        tmp_dx_ball/=10 ;

                        dx_ball=-1*tmp_dx_ball ;
                        dy_ball=random_sign()*tmp_dy_ball ;
                    }

                    destroy_brick(m_renderer , brick_n_text_Texture , wallpaperTexture , i , j , last_bricks_row , last_bricks_column , strength , x_start_brick , y_start_brick , brick_w , brick_h , horizon_bricks_dist , vertic_bricks_dist ) ;

                    update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);

                }



            }
        }
        SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);
        SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL);
        loadboard(m_renderer , boardTexture , xgame_board , ystart_board , board_width , board_height) ;
        filledEllipseRGBA(m_renderer , xend_ball , yend_ball , r_ball , r_ball , 0 , 200 , 0 , 255);
        SDL_RenderPresent(m_renderer);
        SDL_PollEvent(e);
//        if (e->type==SDL_KEYDOWN)
//        {
//            if (e->key.keysym.sym==SDLK_a && xgame_board>=0)
//            {
//                xgame_board-=dx_board;
//            }
//            else if (e->key.keysym.sym==SDLK_d && xgame_board+board_width<=window_W)
//            {
//                xgame_board+=dx_board;
//            }
        POINT mouse;
        GetCursorPos(&mouse);
        xgame_board=mouse.x-board_width/2;

        loadboard(m_renderer , boardTexture , xgame_board , ystart_board , board_width , board_height) ;
        SDL_RenderPresent(m_renderer);
//        }
        if (damage==0)
        {
            level++;

            bool is_row_destroyed=true;

            for(int help_j=0 ; help_j<8 && is_row_destroyed==true ; help_j++)
            {
                if (strength[last_bricks_row][help_j]!=0)
                {
                    last_bricks_row++;
                    is_row_destroyed=false;
                }
            }

            add_brick_row(m_renderer , brick_n_text_Texture , wallpaperTexture , last_bricks_row , last_bricks_column , strength , x_start_brick , y_start_brick , brick_w , brick_h , level , vertic_bricks_dist);

            SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL) ;

            SDL_RenderPresent(m_renderer) ;

            SDL_Delay(200) ;

            char level_left_digit=char(level/10)+ascii_code_0 , level_right_digit=char (level%10)+ascii_code_0 ;
//            cout<<" "<<level_left_digit<<" "<<level_right_digit;
            if (level<=9)
            {
                levelshow[levelshow_length-1]=level_right_digit ;
            }
            else
            {
                levelshow="level : 0";
                levelshow[levelshow_length-1]=level_left_digit;
                levelshow+=level_right_digit;
            }
            damage=level;

            if (damage<=9)
            {
                damageshow = "damage : 1";
                damageshow[damageshow_length-1] = char (damage+ascii_code_0) ;
            }
            else
            {
                damageshow = "damage : 1";

                char damage_left_digit = char (damage/10)+ascii_code_0 , damage_right_digit = char (damage%10)+ascii_code_0 ;

                damageshow[damageshow_length-1] = damage_left_digit ;
                damageshow+=damage_right_digit ;
            }

            update_bottom_text(m_renderer , brick_n_text_Texture , wallpaperTexture , xlevel , xscore , xlives , xdamage , ytext, levelshow , scoreshow , livesshow , damageshow , font , font_size);




            filledEllipseRGBA(m_renderer , xend_ball , yend_ball , r_ball+3 , r_ball+3 , 0 , 0 , 0 , 255);

            xstart_board = xgame_board ;
            yend_ball = ystart_board - r_ball ;
            ystart_ball = ystart_board - r_ball ;
            xend_ball = xstart_board + board_width/2 ;
            xstart_ball = xstart_board + board_width/2 ;

            filledEllipseRGBA(m_renderer , xstart_ball , ystart_ball , r_ball , r_ball , 0 , 200 , 0 , 255);

            SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL);

            loadboard(m_renderer , boardTexture , xstart_board , ystart_board , board_width , board_height) ;

            filledEllipseRGBA(m_renderer , xstart_ball , ystart_ball , r_ball , r_ball , 0 , 200 , 0 , 255);


            SDL_RenderPresent(m_renderer);

            /*tmp_dx_ball=(rand()%17)+4 ,*/ tmp_dy_ball=(rand()%17)+30 , dx_ball , dy_ball ;

            if (tmp_dy_ball/10>=0.75*const_V)
            {
                tmp_dy_ball=7.5*const_V;
            }
            tmp_dx_ball=sqrt(10*const_V*10*const_V-tmp_dy_ball*tmp_dy_ball);

            tmp_dx_ball/=10;
            tmp_dy_ball/=10;

            dx_ball=random_sign()*tmp_dx_ball;
            dy_ball=tmp_dy_ball;

            bool start_game=false;
            while (start_game==false){
                SDL_PollEvent(e);

                if (e->type==SDL_KEYDOWN && e->key.keysym.sym == SDLK_SPACE)
                {
                    start_game=true ;
                    xgame_board=xstart_board ;
                }
                POINT mouse;
                GetCursorPos(&mouse);
                xstart_board=mouse.x-board_width/2;

//                if (e->type==SDL_KEYDOWN)
//                {
//                    int xstart_ball=xstart_board+board_width/2+dx_board,ystart_ball=ystart_board-r_ball;
//                    switch(e->key.keysym.sym)
//                    {
//                        case SDLK_a:
//                            if (xstart_board>=0)
//                            xstart_board-=dx_board;
//                            break;
//                        case SDLK_d:
//                            if (xstart_board+board_width<=window_W)
//                            xstart_board+=dx_board;
//                            break;
//                        case SDLK_SPACE:
//                            start_game=true;
//                            xgame_board=xstart_board;
//                            break;
//                    }

                    xstart_ball=xstart_board+board_width/2 , ystart_ball=ystart_board-r_ball;

                    SDL_RenderCopy(m_renderer , wallpaperTexture , NULL , NULL);

                    SDL_RenderCopy(m_renderer , brick_n_text_Texture , NULL , NULL);

                    loadboard(m_renderer , boardTexture , xstart_board , ystart_board , board_width , board_height) ;

                    filledEllipseRGBA(m_renderer , xstart_ball , ystart_ball , r_ball , r_ball , 0 , 200 , 0 , 255);

                    SDL_RenderPresent(m_renderer);
//                }
            }
            xstart_ball=xstart_board+board_width/2 ;
            ystart_ball=ystart_board-r_ball ;

        }
        if (y_start_brick[last_bricks_row]+brick_h>=ystart_board+board_height)
        {
            gameover = true ;
        }
    }
    if (gameover==true)
    {
        bool founded_first_unsaved=false ;

        int number_of_histories=0 ;

        string name_history = name+"_history_" ;

        for(int k=1 ; (k<=5) && (founded_first_unsaved==false) ; k++)
        {
            name_history = name+"_history_" ;
            char number_of_history = char (k) + ascii_code_0 ;
            name_history+=number_of_history ;

            number_of_histories++ ;

            cout<<endl<<name_history<<endl ;

            load.open(name_history.c_str()) ;

            if (load.good()==false)
            {
                cout<<"load "<<name_history<<" is false"<<endl ;

                founded_first_unsaved=true ;

                load.close() ;
                save.open(name_history.c_str()) ;
                if (save.good())
                {
                    save<<level<<endl ;
                    save<<score<<endl ;
                    save<<lives<<endl ;
                    save.close() ;
                }
            }

            load.close() ;

        }
        number_of_histories++;
        if (founded_first_unsaved==false)
        {
            string number_of_histories_file = name ;
            number_of_histories_file+="_number of histories" ;
            load.open(number_of_histories_file.c_str()) ;
            if (load.good())
            {
                load>>number_of_histories ;
                load.close();

                if (number_of_histories%5==0)
                    number_of_histories=5 ;
                else
                    number_of_histories%=5 ;


                char number_of_history = char (number_of_histories)+ascii_code_0 ;
                name_history = name+"_history_" ;
                name_history+=number_of_history ;


                save.open(name_history.c_str()) ;
                if (save.good())
                {
                    save<<level<<endl ;
                    save<<score<<endl ;
                    save<<lives<<endl ;
                    save.close() ;
                }


                number_of_histories++;

                save.open(number_of_histories_file.c_str());
                if (save.good())
                {
                    save<<number_of_histories ;
                    save.close() ;
                }
            }
            else
            {
                load.close();

                if (number_of_histories%5==0)
                    number_of_histories=5 ;
                else
                number_of_histories%=5 ;


                char number_of_history = char (number_of_histories)+ascii_code_0 ;
                name_history = name+"_history_" ;
                name_history+=number_of_history ;


                save.open(name_history.c_str()) ;
                if (save.good())
                {
                    save<<level<<endl ;
                    save<<score<<endl ;
                    save<<lives<<endl ;
                    save.close() ;
                }



                number_of_histories++;

                save.open(number_of_histories_file.c_str());
                if (save.good())
                {
                    save<<number_of_histories ;
                    save.close() ;
                }

            }
//            if (number_of_histories%5==0)
//                number_of_histories=5 ;
//            else
//            number_of_histories%=5 ;
//
//            char number_of_history = char (number_of_histories)+ascii_code_0 ;
//            name_history = name+"_history_" ;
//            name_history+=number_of_history ;
//
//
//            save.open(name_history.c_str()) ;
//            if (save.good())
//            {
//                save<<level<<endl ;
//                save<<score<<endl ;
//                save<<lives<<endl ;
//                save.close() ;
//            }
//            number_of_histories++;

        }

//        ofstream save_history ;
//        save_history.open(name_history.c_str() , ios::app) ;
//        if (save_history.good())
//        {
//            save_history<<level<<endl ;
//            save_history<<score<<endl ;
//            save_history<<lives<<endl ;
//            save_history<<damage<<endl ;
//
//        }
//        save_history.close() ;



        const char *gameover1 = "GAME OVER!" ;
        const char *gameover2 = "PRESS ANY KEY TO CONTINUE" ;
        textRGBA(m_renderer , window_W/2-175 , window_H/2 , gameover1 , 2 , 70 , 255 , 0 , 20 , 255) ;
        textRGBA(m_renderer , window_W/2-150 , window_H/2+200 , gameover2 , 2 , 20 , 255 , 0 , 20 , 255) ;
        SDL_RenderPresent(m_renderer) ;
        SDL_Delay(1000) ;
        e->type=0 ;
        while (e->type!=SDL_KEYDOWN)
            SDL_PollEvent(e) ;
    }
    else
    {
        save.open(name.c_str()) ;
        if (save.good())
        {
            save<<level<<endl;
            save<<score<<endl;
            save<<lives<<endl;
            save<<damage<<endl;
            save<<last_bricks_row<<endl;
            for (i=last_bricks_row ; i>=0 ; i--)
            {
                for (j=0 ; j<=last_bricks_column ; j++)
                {
                    save<<strength[i][j]<<endl;
                }
//                save<<endl;
            }

            save.close() ;
        }
    }





    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;
}


