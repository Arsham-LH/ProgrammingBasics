#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>

// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com


using namespace std;




int main( int argc, char * argv[] )
{
//    int n;
//    cout<<"Enter n:";
//    cin>>n;
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN; //| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

//    int img_w, img_h;
//    SDL_Rect img_rect;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 800, 480, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
//
//    // Show the window
    SDL_RenderPresent( m_renderer );
    double xO=400,yO=40,rx=40,ry=40,sign=1,y_last=40;
    double v=0;
        SDL_Event *e = new SDL_Event();
        while((fabs(v)>4.9)||(yO<440))
    {
    v+=sign*1.6;
    if ((v==0))
    y_last=yO;
    yO+=sign*v;
    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,50,200,150,255);
    SDL_RenderPresent( m_renderer );
    SDL_Delay(40);
    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,0,0,0,255);
    SDL_RenderPresent( m_renderer );
    if (yO>440)
    {
//    yO=439;
    ry-=fabs(v)/2;
    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,50,200,150,255);
    SDL_RenderPresent( m_renderer );
    SDL_Delay(40);
    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,0,0,0,255);
    SDL_RenderPresent( m_renderer );
    ry+=fabs(v)/2;

        sign*=-1;
    }
    }
    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,50,200,150,255);
    SDL_RenderPresent( m_renderer );

    while (e->type!=SDL_KEYDOWN)
        SDL_PollEvent(e);



//    if (yO>480-40){
//                filledEllipseRGBA(m_renderer,xO,yO,rx,ry,50,200,150,255);
//    SDL_RenderPresent( m_renderer );
//    SDL_Delay(80);
//    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,0,0,0,255);
//    SDL_RenderPresent( m_renderer );
//
//        sign*=-1;
//        ry-=15;
//    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,50,200,150,255);
//    SDL_RenderPresent( m_renderer );
//    SDL_Delay(40);
//    filledEllipseRGBA(m_renderer,xO,yO,rx,ry,0,0,0,255);
//    SDL_RenderPresent( m_renderer );
//        ry+=15;
//    filledEllipseRGBA(m_renderer,xO,yO,40,40,50,200,150,255);
//    SDL_RenderPresent( m_renderer );
//    SDL_Delay(40);
//    filledEllipseRGBA(m_renderer,xO,yO,40,40,0,0,0,255);
//    SDL_RenderPresent( m_renderer );
//    if (y_last<440)
//    y_last+=50;
//    }
//    filledEllipseRGBA(m_renderer,xO,yO,40,40,50,200,150,255);
//    SDL_RenderPresent( m_renderer );
//    SDL_Delay(80);
//    filledEllipseRGBA(m_renderer,xO,yO,40,40,0,0,0,255);
//    SDL_RenderPresent( m_renderer );
//    if (yO<y_last)
//        sign*=-1;
//    }
//    while(e->type != SDL_KEYDOWN){
//    filledEllipseRGBA(m_renderer,xO,yO,40,40,50,200,150,255);
//    SDL_RenderPresent( m_renderer );
//    SDL_PollEvent(e);
//    }









//
//
//    // Render a new color bar every 0.5 seconds
//    for ( int i = 0; i < 256; i++)
//    {
//        aalineRGBA(m_renderer, i, 50, i, 500, i, 0, 0, 255);
//        SDL_RenderPresent( m_renderer );
//        SDL_Delay( 1 );
//    }
//
//    filledEllipseRGBA(m_renderer, 0, 100, 100, 50, 100, 200, 0, 127);
//    hlineRGBA(m_renderer, 0, W, H/2, 0, 0, 255, 255);
//    aalineRGBA(m_renderer, 200, 200, 400, 500, 0, 255, 0, 255);
//    aalineColor(m_renderer, 220, 220, 420, 520, 0xFF00FF00);
//
//    int L = 500;
//    for(int i = 0; i <= n; i++)
//    {
//        aalineRGBA(m_renderer, 200, 200 + i * L / n, 200 + i * L / n, 200+L, 255, 255, 255, 255);
//        SDL_RenderPresent( m_renderer );
//        SDL_Delay(20);
//    }
//
//
//const char * text ="WELCOME TO SHARIF EE DEPARTMENT!!";
//
//// 1 for lazy.ttf , 2 for arial.ttf , 3 for B Roya.ttf
//int font =2;
//int x_position=500;
//int y_position=600;
//int R=255;
//int G =2;
//int B=3;
//int A=0.5;
//SDL_Color text_color = { 250, 250, 250};
//     textColor(m_renderer,x_position,y_position,text,font ,24,text_color);
//     textRGBA(m_renderer,x_position+100,y_position+100,text,font ,24,R,G,B,A);
//
//
//
//SDL_Texture* m_img = NULL;
//
//
//    //Wait for a key to be pressed
//
//    //Loading image
//    m_img = IMG_LoadTexture(m_renderer, IMG_address_01);
//    //Get the width and height of the texture
//    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
//    img_rect.x = 1000;
//    img_rect.y = 200;
//    img_rect.w = img_w * 1;
//    img_rect.h = img_h * 1;
//    // copy the texture to the rendering context
//    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
//    SDL_RenderPresent( m_renderer );
//    e->type = 0;
//
//    //Wait for a key to be pressed
//    while(e->type != SDL_KEYDOWN)
//        SDL_PollEvent(e);

    //Finalize and free resources
//    SDL_DestroyTexture(m_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}


