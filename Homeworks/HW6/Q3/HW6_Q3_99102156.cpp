#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include<cmath>

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
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

//    int img_w, img_h;
//    SDL_Rect img_rect;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1200, 800, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
//    SDL_GetCurrentDisplayMode(0, &DM);



    int W = 1200;
    int H = 800;
SDL_Texture *mTexture;
 mTexture = SDL_CreateTexture( m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , W, H );
 SDL_SetRenderTarget(m_renderer,mTexture);
boxRGBA(m_renderer,0,0,W,H-350,255,255,255,255);
SDL_SetRenderTarget(m_renderer,NULL);
SDL_RenderCopy(m_renderer,mTexture,NULL,NULL);
    SDL_RenderPresent( m_renderer );
//    SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 255 );
//    SDL_RenderClear( m_renderer );

    // Clear the window with a black background

    // Show the window
    bool quit=false;
    double R=45,r=10,Xc=100,Yc=H-350-R,d=35,center_distance=R+R+d,Xs1=Xc+3,Xe1=Xs1+4*center_distance-3,Ys1=Yc-170,Ye1=Ys1+160,Lx=180,Ly=50;
    double Xs2=Xs1+Lx,Ys2=Ys1-Ly,Xe2=Xe1-Lx,Ye2=Ys1,Xs3=(Xe2-Xs2)/2+Xs2,Ys3=Ys2+Ly/2,Xe3=Xs3+200,Ye3=Ys3+8,x=0,pipe_length=Xe3-Xs3,th=0;
    double r_rotate=sqrt(pow(Xe3-Xs3,2)+pow(Ye3-Ys3,2));
        SDL_Event *e = new SDL_Event();
        while(quit==false){
        SDL_PollEvent(e);
        if (e->type==SDL_KEYDOWN)
        {
            switch (e->key.keysym.sym){
        case SDLK_a:
            if (Xs1+x-R>3)
            x-=5;
            break;
        case SDLK_d:
            if (Xe1+x+R<=1197)
            x+=5;
            break;
        case SDLK_w:
            if (th<M_PI/2.5)
            th+=0.02;
            break;
        case SDLK_s:
            if (th>-0.18)
            th-=0.02;
            break;
        default:
            quit=true;
            }
            Xe3=sqrt(r_rotate*r_rotate-(Ye3-Ys3)*(Ye3-Ys3))+Xs3;
            SDL_RenderCopy(m_renderer,mTexture,NULL,NULL);
        }
    Xc=100;
    for (Xc;Xc<=5*center_distance;Xc+=center_distance)
    {
        filledEllipseRGBA(m_renderer,Xc+x,Yc,R,R,100,100,100,255);
        filledEllipseRGBA(m_renderer,Xc+x,Yc,r,r,0,0,0,255);
    }
        boxRGBA(m_renderer,Xs2+x,Ys2,Xe2+x,Ye2,0,25,0,255);
        for (int j=Ys3;j<=Ye3;j++)
        {
            aalineRGBA(m_renderer, Xs3+x, j , Xs3+x+pipe_length*cos(th/2), j-pipe_length*sin(th/2),50,50,50,255);
        }

        boxRGBA(m_renderer,Xs1+x,Ys1,Xe1+x,Ye1,20,50,100,255);
        SDL_RenderPresent(m_renderer);
        }



//    e->type = 0;
//
    //Wait for a key to be pressed

    //Finalize and free resources
//    SDL_DestroyTexture(m_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}


