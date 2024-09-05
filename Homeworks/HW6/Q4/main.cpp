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
    SDL_RenderPresent(Renderer);

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




int main( int argc, char * argv[] )
{
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1200, 800, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;



    int W = 1200;
    int H = 800;
SDL_Texture *mTexture;
 mTexture = SDL_CreateTexture( m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , W, H );
 SDL_SetRenderTarget(m_renderer,mTexture);
boxRGBA(m_renderer,0,0,W,H-350,255,255,255,255);
rect(m_renderer,W-35,H-800,35,450,149,44,55,1);
SDL_SetRenderTarget(m_renderer,NULL);
SDL_RenderCopy(m_renderer,mTexture,NULL,NULL);
    SDL_RenderPresent( m_renderer );
    bool quit=false;
    int sign=1,flag=0,counter=501;
    double R=45,r=10,Xc=100,Yc=H-350-R,d=35,center_distance=R+R+d,Xs1=Xc+3,Xe1=Xs1+4*center_distance-3,Ys1=Yc-170,Ye1=Ys1+160,Lx=180,Ly=50;
    double Xs2=Xs1+Lx,Ys2=Ys1-Ly,Xe2=Xe1-Lx,Ye2=Ys1,Xs3=(Xe2-Xs2)/2+Xs2,Ys3=Ys2+Ly/2,Xe3=Xs3+200,Ye3=Ys3+8,x=0,pipe_length=Xe3-Xs3,th=0,tmp_th=th,tmp=0;
    double r_rotate=sqrt(pow(Xe3-Xs3,2)+pow(Ye3-Ys3,2)),Xspipe=Xs3+x,Xepipe=Xs3+x+pipe_length*cos(2*th/2),Yspipe=0,Yepipe=0,Yshoot,v0=100,xb=W/2,k=0,yb=H/2,xb_start=Xepipe;
    SDL_Event *e = new SDL_Event();
    while(quit==false){
        SDL_PollEvent(e);
        SDL_Delay(1);
        counter++;
        if (e->type==SDL_KEYDOWN)
        {
            switch (e->key.keysym.sym){
                case SDLK_a:
                    if (Xs1+x-R>3)
                    x-=5;
                    SDL_PollEvent(e);
                    if (e->type==SDL_KEYDOWN)
                    {
                        switch (e->key.keysym.sym){
                            case SDLK_w:
                                if (th<M_PI/2.5)
                                th+=0.02;
                                break;
                            case SDLK_s:
                                if (th>-0.08)
                                th-=0.02;
                                break;
                        }
                    }
                    break;
                case SDLK_d:
                    if (Xe1+x+R<=1197-35)
                    x+=5;
                    SDL_PollEvent(e);
                    if (e->type==SDL_KEYDOWN)
                    {
                        switch (e->key.keysym.sym){
                            case SDLK_w:
                                if (th<M_PI/2.5)
                                th+=0.02;
                                break;
                            case SDLK_s:
                                if (th>-0.08)
                                th-=0.02;
                                break;
                        }
                    }
                    break;
                case SDLK_w:
                    if (th<M_PI/2.5)
                    th+=0.02;
                    SDL_PollEvent(e);
                    if (e->type==SDL_KEYDOWN)
                    {
                        switch (e->key.keysym.sym){
                            case SDLK_a:
                                if (Xs1+x-R>3)
                                x-=5;
                                break;
                            case SDLK_d:
                                if (Xe1+x+R<=1197-35)
                                x+=5;
                                break;
                        }
                    }
                    break;
                case SDLK_s:
                    if (th>-0.08)
                    th-=0.02;
                    SDL_PollEvent(e);
                    if (e->type==SDL_KEYDOWN)
                    {
                        switch (e->key.keysym.sym){
                            case SDLK_a:
                                if (Xs1+x-R>3)
                                x-=5;
                                break;
                            case SDLK_d:
                                if (Xe1+x+R<=1197-35)
                                x+=5;
                                break;
                        }
                    }
                    break;
                case SDLK_f :
                    if (counter>=500){
                        counter=0;
                        xb_start=Xepipe;
                        tmp_th=th;
                        for (k=0;(xb>0)&&xb<W-35-10&&yb<H;k+=0.15){
                            tmp+=0.15;
                            xb=xb_start+sign*v0*cos(tmp_th)*tmp;
                            Yshoot=-0.5*9.78*k*k+v0*sin(tmp_th)*k;
                            yb=Yepipe-Yshoot;
                            filledEllipseRGBA(m_renderer,xb,yb,10,10,20,150,255,255);
                            SDL_RenderPresent(m_renderer);
                            SDL_Delay(20);
                            counter++;
                            SDL_RenderCopy(m_renderer,mTexture,NULL,NULL);
                            SDL_PollEvent(e);
                            if (e->type==SDL_KEYDOWN)
                            {
                                switch (e->key.keysym.sym){
                                    case SDLK_a:
                                        if (Xs1+x-R>3)
                                        x-=8;
                                        break;
                                    case SDLK_d:
                                        if (Xe1+x+R<=1197-35)
                                        x+=8;
                                        break;
                                    case SDLK_w:
                                        if (th<M_PI/2.5)
                                        th+=0.03;
                                        break;
                                    case SDLK_s:
                                        if (th>-0.08)
                                        th-=0.03;
                                        break;
                                }
                            }
                                    for (Xc=100;Xc<=5*center_distance;Xc+=center_distance)
                                    {
                                        filledEllipseRGBA(m_renderer,Xc+x,Yc,R,R,100,100,100,255);
                                        filledEllipseRGBA(m_renderer,Xc+x,Yc,r,r,0,0,0,255);
                                    }
                                        boxRGBA(m_renderer,Xs2+x,Ys2,Xe2+x,Ye2,0,25,0,255);
                                        for (int j=Ys3;j<=Ye3;j++)
                                        {
                                            Xspipe=Xs3+x;
                                            Xepipe=Xs3+x+pipe_length*cos(2*th/2);
                                            Yspipe=j;
                                            Yepipe=j-pipe_length*sin(2*th/2);
                                            aalineRGBA(m_renderer, Xspipe, Yspipe , Xepipe,Yepipe ,50,50,50,255);
                                        }

                                        boxRGBA(m_renderer,Xs1+x,Ys1,Xe1+x,Ye1,20,50,100,255);
                                        SDL_RenderPresent(m_renderer);
                                    if (xb+0.15*v0*cos(th)>=W-35-10)
                                    {
                                        xb_start=W-35-10;
                                        sign=-1;
                                        tmp=0.15;
                                    }
                            }
                    }
                            k=0;
                            tmp=0;
                            sign=1;
                            xb_start=Xepipe;
                            xb=xb_start;
                            yb=Yepipe;
                            cout<<counter<<" ";
                            break;
                        default:
                            quit=true;
                            break;
            }
            SDL_RenderCopy(m_renderer,mTexture,NULL,NULL);
        }
        e->type=0;
        if (counter>500)
            cout<<counter<<" ";
    for (Xc=100;Xc<=5*center_distance;Xc+=center_distance)
    {
        filledEllipseRGBA(m_renderer,Xc+x,Yc,R,R,100,100,100,255);
        filledEllipseRGBA(m_renderer,Xc+x,Yc,r,r,0,0,0,255);
    }
        boxRGBA(m_renderer,Xs2+x,Ys2,Xe2+x,Ye2,0,25,0,255);
        for (int j=Ys3;j<=Ye3;j++)
        {
            Xspipe=Xs3+x;
            Xepipe=Xs3+x+pipe_length*cos(2*th/2);
            Yspipe=j;
            Yepipe=j-pipe_length*sin(2*th/2);
            aalineRGBA(m_renderer, Xspipe, Yspipe , Xepipe,Yepipe ,50,50,50,255);
        }

        boxRGBA(m_renderer,Xs1+x,Ys1,Xe1+x,Ye1,20,50,100,255);
        SDL_RenderPresent(m_renderer);
    }
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;
}



