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
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);

using namespace std;




int main( int argc, char * argv[] )
{
    int n;
//    cout<<"Enter n:";
//    cin>>n;
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

    int img_w, img_h;
    SDL_Rect img_rect;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1200, 480, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    SDL_Texture* mtexture;

    //Get screen resolution
//    SDL_DisplayMode DM;
//    SDL_GetCurrentDisplayMode(0, &DM);
//    int W = DM.w;
//    int H = DM.h;
int H=480,W=1200;
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
int i,w=200,h=200;
//    SDL_RenderPresent( m_renderer );
for (i=0;i<W-w;i++)
{
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
    SDL_RenderClear(m_renderer);

//    SDL_SetRenderTarget(m_renderer,mtexture);
    rect(m_renderer,0+i,H/2-h/2,w,h,0,120,120,1);
    rect(m_renderer,W-w-i,H/2-h/2,w,h,25,80,60,1);
    SDL_Delay(15);
    if(0+i+w>W-w-i)
    {
         int j=2*i+2*w-W;
         if (j<=w)
         {

            rect(m_renderer,W/2-j/2,H/2-h/2,j,h,255,255-255*j/w,255-255*j/w,1);
            SDL_RenderPresent(m_renderer);
         }
         else if(i>=W/2-w/2&&i<=W/2)
         {
            rect(m_renderer,i,H/2-h/2,2*(W/2-i),h,255,255*2*(i-W/2+w/2)/w,255*2*(i-W/2+w/2)/w,1);
            SDL_RenderPresent(m_renderer);
         }
    }
//    SDL_SetRenderTarget(m_renderer,NULL);
//    SDL_RenderCopy(m_renderer,mtexture,NULL,NULL);
    SDL_RenderPresent(m_renderer);
}
    // Render a new color bar every 0.5 seconds
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
//
//
//    //Wait for a key to be pressed
    SDL_Event *e = new SDL_Event();
//    while(e->type != SDL_KEYDOWN)
//        SDL_PollEvent(e);
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

    //Wait for a key to be pressed
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);
    rect(m_renderer,0,H/2-h,w,h,200,120,120,255);

    //Finalize and free resources
//    SDL_DestroyTexture(m_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

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


