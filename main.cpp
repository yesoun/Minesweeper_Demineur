#include <SDL.h>
#include <SDL/SDL_ttf.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


struct cellule
{
    int val;
    bool select;
    int choix;
};
using namespace std;
void remplir(cellule **grille);
void remplir1(cellule**grille);
void remplir2(cellule**grille);
void jeu (cellule **grille,int i,int j);
void jeu1(cellule **grille,int i,int j);
void affichage(cellule **grille);
void affichage1(cellule **grille);
void jeu2(cellule **grille,int i,int j);
void affichage2(cellule **grille);

int main(int argc, char *argv[])
{
int k,l,s,w,x,test=0,fin=0,commencer=0,LMAX=0,CHOI=0,recommencer=0;
int i,j,nbre,c;
string ch;
int n;//nombre des bombes
cellule **grille;
SDL_Surface *ecran = NULL,*accueil=NULL,*arrier=NULL,*un=NULL,*deux=NULL,*trois=NULL,*quatre=NULL,*cinq=NULL,*six=NULL,*sept=NULL,*huit=NULL,*bombe=NULL,*case_cache2=NULL,*case_vide=NULL,*case_cache=NULL,*flag=NULL,*interrogation=NULL,*levels=NULL,*unA=NULL,*deuxA=NULL,*troisA=NULL,*quatreA=NULL,*cinqA=NULL,*sixA=NULL,*septA=NULL,*huitA=NULL,*bombe2=NULL,*case_vide2=NULL,*flag2=NULL,*interrogation2=NULL;
SDL_Surface *bravo=NULL,*echec=NULL,*rejouer1=NULL,*rejouer2=NULL,*jouer1=NULL,*jouer2=NULL,*quitter=NULL,*texte=NULL,*font_jeu=NULL;
SDL_Rect position;
SDL_Event event;
TTF_Font *police = NULL;
SDL_Color couleur = {155, 155, 100};
int tempsActuel = 0, tempsPrecedent = 0, compteur1 = 0 , compteur2 = 0;
char temps[20] = "";
char mine[20] = "";
int mines=0;

accueil=SDL_LoadBMP("accueil.bmp");
un=SDL_LoadBMP("1.bmp");
deux=SDL_LoadBMP("2.bmp");
trois=SDL_LoadBMP("3.bmp");
quatre=SDL_LoadBMP("4.bmp");
cinq=SDL_LoadBMP("5.bmp");
six=SDL_LoadBMP("6.bmp");
sept=SDL_LoadBMP("7.bmp");
huit=SDL_LoadBMP("8.bmp");
bombe=SDL_LoadBMP("bombe.bmp");
case_vide2=SDL_LoadBMP("case-vide2.bmp");
case_cache2=SDL_LoadBMP("case-cache2.bmp");
unA=SDL_LoadBMP("11.bmp");
deuxA=SDL_LoadBMP("12.bmp");
troisA=SDL_LoadBMP("13.bmp");
quatreA=SDL_LoadBMP("14.bmp");
cinqA=SDL_LoadBMP("15.bmp");
sixA=SDL_LoadBMP("16.bmp");
septA=SDL_LoadBMP("17.bmp");
huitA=SDL_LoadBMP("18.bmp");
bombe2=SDL_LoadBMP("bombe2.bmp");
case_cache=SDL_LoadBMP("case-cache.bmp");
case_vide=SDL_LoadBMP("case-vide.bmp");
flag=SDL_LoadBMP("flag.bmp");
interrogation=SDL_LoadBMP("interrogation.bmp");
flag2=SDL_LoadBMP("flag2.bmp");
interrogation2=SDL_LoadBMP("interrogation2.bmp");
levels=SDL_LoadBMP("levels.bmp");
bravo=SDL_LoadBMP("bravo.bmp");
echec=SDL_LoadBMP("echec.bmp");
jouer1=SDL_LoadBMP("jouer1.bmp");
jouer2=SDL_LoadBMP("jouer2.bmp");
rejouer1=SDL_LoadBMP("rejouer1.bmp");
rejouer2=SDL_LoadBMP("rejouer2.bmp");
quitter=SDL_LoadBMP("quitter.bmp");
arrier=SDL_LoadBMP("arrier.bmp");
font_jeu=SDL_LoadBMP("dans_le_jeu.bmp");

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
ecran = SDL_SetVideoMode(600, 400, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));


position.x = 0;
position.y = 0;
SDL_BlitSurface(accueil, NULL, ecran, &position);
position.x = 100;
position.y = 300;
SDL_BlitSurface(jouer1, NULL, ecran, &position);
position.x = 350;
position.y = 250;
SDL_BlitSurface(quitter, NULL, ecran, &position);
SDL_Flip(ecran);

while (commencer==0 || commencer==1 ||commencer==2)
{
SDL_WaitEvent(&event);
        switch(event.type)
            {
                case SDL_QUIT:
                return EXIT_SUCCESS;
            break;
            case SDL_MOUSEMOTION:
                    i=event.motion.x;
                    j=event.motion.y;
                    if (i<230 && i>100 && j<360 && j>300)
                    {
                        commencer=1;
                        position.x = 100;
                        position.y = 300;
                        SDL_BlitSurface(jouer2, NULL, ecran, &position);
                        SDL_Flip(ecran);
                    }
                    else
                    {
                       if (i<480 && i>350 && j<380 && j>250)
                    {
                        commencer=2;
                    }
                    else
                    {
                        commencer=0;
                        position.x = 100;
                        position.y = 300;
                        SDL_BlitSurface(jouer1, NULL, ecran, &position);
                        position.x = 350;
                        position.y = 250;
                        SDL_BlitSurface(quitter, NULL, ecran, &position);
                        SDL_Flip(ecran);
                    }
                    }


                    break;
                case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
{
    if (commencer== 2)
    {
        return EXIT_SUCCESS;
    }
    if (commencer==1)
    {
        commencer=3;
    }
}
break;
            }
}

position.x = 0;
position.y = 0;
SDL_BlitSurface(levels, NULL, ecran, &position);
SDL_Flip(ecran);
commencer=0;

while (commencer==0 || commencer==1 ||commencer==2 || commencer==3)
{
SDL_WaitEvent(&event);
        switch(event.type)
            {
                case SDL_QUIT:
                return EXIT_SUCCESS;
            break;
            case SDL_MOUSEMOTION:
                    i=event.motion.x;
                    j=event.motion.y;
                    if (i<270 && i>67 && j<200 && j>158)
                    {
                        commencer=1;
                    }
                    else
                    {
                       if (i<270 && i>67 && j<266 && j>222)
                    {
                        commencer=2;
                    }
                    else
                    {
                        if (i<270 && i>67 && j<325 && j>282)
                    {
                        commencer=3;
                    }
                    else
                    {
                        commencer=0;
                    }
                    }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
{
    if (commencer== 1)
    {
        commencer=4;
        LMAX=9;
    }
    if (commencer==2)
    {
        commencer=5;
        LMAX=16;
    }
    if (commencer==3)
    {
        commencer=6;
        LMAX=30;
    }
}
break;
            }
}



int LARGEUR_FENETRE=LMAX*30;
srand(time(NULL));

//allocation:
switch (commencer){
case 4:
{


grille = new cellule*[9];

for(i=0;i<9;i++) {

grille[i] = new cellule[9];

}
}
case 5:
{{


grille = new cellule*[16];

for(i=0;i<16;i++) {

grille[i] = new cellule[16];

}}}
case 6:{{


grille = new cellule*[30];

for(i=0;i<30;i++) {

grille[i] = new cellule[30];

}
}}}
switch (commencer) {
case 4:
{
for (i=0; i<9; i++)
{
for (j=0; j<9; j++)

{
grille[i][j].val = 0;
grille[i][j].select = false;
grille[i][j].choix = 0;

}

}
n=10;

break;

}
case 5 :
{
for (i=0; i<16; i++)
{
for (j=0; j<16; j++)

{
grille[i][j].val = 0;
grille[i][j].select = false;
grille[i][j].choix = 0;
}


}
n=40;
break;
}
case 6 :
{
for (i=0; i<30; i++)
{
for (j=0; j<30; j++)
{
grille[i][j].val = 0;
grille[i][j].select = false;
grille[i][j].choix = 0;

}


}
n=99;
break;
}};
//la remplissage de grille

switch (commencer){
case 4:
{

int continuer=1;
fin=0;
test=0;
recommencer=0;

while (continuer)
{
ecran = SDL_SetVideoMode(LARGEUR_FENETRE+ 5*LMAX, LARGEUR_FENETRE+20+10*LMAX, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
s=0;
fin=0;
test=0;
recommencer=0;
compteur1=0;
compteur2=0;
mines=9;
for (int k=0;k<9;k++)
{
    for (int l=0;l<9;l++)
    {
        grille[k][l].val=0;
        grille[k][l].select = false;
        grille[k][l].choix = 0;
    }
}

while (s<9 )
{

k=rand()%8+0;
l=rand()%8+0;
if (grille[k][l].val!=9)
{

grille[k][l].val=9;
s=s++;
}

}



remplir(grille);



position.x = 0;
position.y = 0;
SDL_BlitSurface(font_jeu, NULL, ecran, &position);

for (int k=0 ; k<LMAX ; k++)
            {
                for (int l=0 ; l<LMAX ; l++)
                {
                 position.x = l * 35;
                 position.y = k * 35;
                 SDL_BlitSurface(case_cache, NULL, ecran, &position);
                }
            }
SDL_Flip(ecran);
  /* Chargement de la police */
police = TTF_OpenFont("algerien.ttf", 25);
/* Initialisation du temps et du texte */
tempsActuel = SDL_GetTicks();
sprintf(temps, "%d: %d", compteur2,compteur1);
texte = TTF_RenderText_Solid(police, temps, couleur);

int i=9,j=9,m=9,n=9;
do
{
    test=0;
    do
    {
        SDL_Delay(100);
        CHOI=3;
        SDL_PollEvent(&event);
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 1000) /* Si 1000ms au moins se sont écoulées */
        {
        compteur1+=1;
        if (compteur1==60)
        {
        compteur1=0;
        compteur2 +=1;
        }

        tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }
        sprintf(temps, "Temps %d: %d", compteur2,compteur1); /* On écrit dans la chaîne "temps" le nouveau temps */
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, temps,couleur); /* On écrit la chaine temps dans la SDL_Surface */
        position.x = 70;
        position.y = 320;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format,255,255,255));
        position.x = 0;
        position.y = 320;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte contenant le temps */
        sprintf(mine, "Mines: %d", mines); /* On écrit dans la chaîne "temps" le nouveau temps */
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, mine,couleur);
        position.x = 190;
        position.y = 320;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_Flip(ecran);
        switch(event.type)
            {
                case SDL_QUIT:
                return EXIT_SUCCESS;
            break;
            case SDL_MOUSEMOTION:
                    k=event.motion.y;
                    if (k<30 && k>0)
                    {
                       m=0;
                    }
                    else
                    {
                          if (k<65 && k>35 )
                        {
                            m=1;
                        }
                        else
                        {
                                if (k<100 && k>70)
                            {
                                m=2;
                            }
                            else
                            {
                                    if (k<135 && k>105)
                                {
                                    m=3;
                                }
                                else
                                {
                                        if (k<170 && k>140 )
                                    {
                                        m=4;
                                    }
                                    else
                                    {
                                            if (k<205 && k>175)
                                        {
                                            m=5;
                                        }
                                        else
                                        {
                                                if (k<240 && k>210)
                                            {
                                                m=6;
                                            }
                                            else
                                            {
                                                    if (k<275 && k>245)
                                                {
                                                    m=7;
                                                }
                                                else
                                                {
                                                    if (k<310 && k>280)
                                                {
                                                    m=8;
                                                }
                                                else
                                                {
                                                    m=9;
                                                }
                                                }

                                            }

                                        }

                                    }

                                }

                            }

                        }

                    }

                    l=event.motion.x;
                    if (l<30 && l>0)
                    {
                       n=0;
                    }
                    else
                    {
                            if (l<65 && l>35 )
                        {
                            n=1;
                        }
                        else
                        {
                                if (l<100 && l>70)
                            {
                                n=2;
                            }
                            else
                            {
                                    if (l<135 && l>105)
                                {
                                    n=3;
                                }
                                else
                                {
                                        if (l<170 && l>140 )
                                    {
                                        n=4;
                                    }
                                    else
                                    {
                                            if (l<205 && l>175)
                                        {
                                            n=5;
                                        }
                                        else
                                        {
                                                if (l<240 && l>210)
                                            {
                                                n=6;
                                            }
                                            else
                                            {
                                                    if (l<275 && l>245)
                                                {
                                                    n=7;
                                                }
                                                else
                                                {
                                                        if (l<310 && l>280)
                                                    {
                                                        n=8;
                                                    }
                                                    else
                                                    {
                                                        n=9;
                                                    }
                                                }

                                            }

                                        }

                                    }

                                }

                            }

                        }

                    }

                    break;
                case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT )
{
    if (m<9 && n<9)
    {
        i=m;
        j=n;
        CHOI=0;
        if (grille[m][n].choix==1 && grille[m][n].select==false)
       {
           mines+=1;
       }
    }


}
else
{
    if ( event.button.button == SDL_BUTTON_RIGHT)
    {
       if (m<9 && n<9 && grille[m][n].select==false)
       {
                i=m;
                j=n;
                if (grille[i][j].choix == 0)
                {
                    grille[i][j].choix = 1;
                    mines-=1;
                    CHOI=1;
                    break;
                }
                if (grille[i][j].choix == 1)
                {
                    grille[i][j].choix = 2;
                    mines+=1;
                    CHOI=1;
                    break;
                }
                if (grille[i][j].choix == 2)
                {
                    grille[i][j].choix = 0;
                    CHOI=1;
                    break;
                }

       }
    }
}
break;
    }
    }
    while (i>8 || j>8 || CHOI==3);


        if (grille[i][j].val!=9 && CHOI==0)
        {
                jeu(grille,i,j);
          for (int k=0 ; k<9 ; k++)
                {
                    for (int l=0 ; l<9 ; l++)
                    {
                        position.x = l * 35;
                        position.y = k * 35;
                     if (grille[k][l].select==true)
                     {
                         switch (grille[k][l].val)
                         {
                             case 0:
                             SDL_BlitSurface(case_vide, NULL, ecran, &position);
                             break;
                             case 1:
                             SDL_BlitSurface(un, NULL, ecran, &position);
                             break;
                             case 2:
                             SDL_BlitSurface(deux, NULL, ecran, &position);
                             break;
                             case 3:
                             SDL_BlitSurface(trois, NULL, ecran, &position);
                             break;
                             case 4:
                             SDL_BlitSurface(quatre, NULL, ecran, &position);
                             break;
                             case 5:
                             SDL_BlitSurface(cinq, NULL, ecran, &position);
                             break;
                             case 6:
                             SDL_BlitSurface(six, NULL, ecran, &position);
                             break;
                             case 7:
                             SDL_BlitSurface(sept, NULL, ecran, &position);
                             break;
                             case 8:
                             SDL_BlitSurface(huit, NULL, ecran, &position);
                             break;
                         }
                     }
                     else
                     {
                            switch (grille[k][l].choix)
                             {
                                 case 0:
                                 SDL_BlitSurface(case_cache, NULL, ecran, &position);
                                 break;
                                 case 1:
                                 SDL_BlitSurface(flag, NULL, ecran, &position);
                                 break;
                                 case 2:
                                 SDL_BlitSurface(interrogation, NULL, ecran, &position);
                                 break;
                             }
                        }
                     }
                    }
                }
                SDL_Flip(ecran);

        if (CHOI==1)
        {
            for (int k=0 ; k<9 ; k++)
                {
                    for (int l=0 ; l<9 ; l++)
                    {
                        position.x = l * 35;
                        position.y = k * 35;
                        if (grille[k][l].select==false)
                        {
                            switch (grille[k][l].choix)
                             {
                                 case 0:
                                 SDL_BlitSurface(case_cache, NULL, ecran, &position);
                                 break;
                                 case 1:
                                 SDL_BlitSurface(flag, NULL, ecran, &position);
                                 break;
                                 case 2:
                                 SDL_BlitSurface(interrogation, NULL, ecran, &position);
                                 break;
                             }
                        }
                    }
                }
                SDL_Flip(ecran);
        }

        if (grille[i][j].val==9 && CHOI==0)
    {
        fin=1;
        // affichage de la fin du jeu
        for (int k=0 ; k<9 ; k++)
            {
                for (int l=0 ; l<9 ; l++)
                {
                    position.x = l * 35;
                 position.y = k * 35;
                 if (grille[k][l].val==9)
                 {
                 SDL_BlitSurface(bombe, NULL, ecran, &position);
                 }
                 else
                 {
                     switch (grille[k][l].val)
                     {
                         case 0:
                         SDL_BlitSurface(case_vide, NULL, ecran, &position);
                         break;
                         case 1:
                         SDL_BlitSurface(un, NULL, ecran, &position);
                         break;
                         case 2:
                         SDL_BlitSurface(deux, NULL, ecran, &position);
                         break;
                         case 3:
                         SDL_BlitSurface(trois, NULL, ecran, &position);
                         break;
                         case 4:
                         SDL_BlitSurface(quatre, NULL, ecran, &position);
                         break;
                         case 5:
                         SDL_BlitSurface(cinq, NULL, ecran, &position);
                         break;
                         case 6:
                         SDL_BlitSurface(six, NULL, ecran, &position);
                         break;
                         case 7:
                         SDL_BlitSurface(sept, NULL, ecran, &position);
                         break;
                         case 8:
                         SDL_BlitSurface(huit, NULL, ecran, &position);
                         break;
                     }
                 }
                }
            }
            SDL_Flip(ecran);
            SDL_Delay(1000);
            ecran = SDL_SetVideoMode(400, 400, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            position.x = 0;
            position.y = 0;
            SDL_BlitSurface(arrier, NULL, ecran, &position);
            position.x = 80;
            position.y = 50;
            SDL_BlitSurface(echec, NULL, ecran, &position);
            position.x = 0;
            position.y = 170;
            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
            position.x = 170;
            position.y = 170;
            SDL_BlitSurface(quitter, NULL, ecran, &position);
            SDL_Flip(ecran);
            int continuer = 1;
            SDL_Event event;
             while (recommencer==0 || recommencer==1 || recommencer==2)
            {
            SDL_WaitEvent(&event);
                            switch(event.type)
                                {
                                case SDL_QUIT:
                                return EXIT_SUCCESS;
                                break;
                                case SDL_MOUSEMOTION:
                                        i=event.motion.x;
                                        j=event.motion.y;
                                        if (i<130 && i>0 && j<300 && j>170)
                                        {
                                            recommencer=1;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer2, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        else
                                        {
                                           if (i<300 && i>170 && j<300 && j>170)
                                        {
                                            recommencer=2;
                                        }
                                        else
                                        {
                                            recommencer=0;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        }

                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (recommencer== 2)
                        {
                                return EXIT_SUCCESS;
                        }
                        if (recommencer== 1)
                        {
                                recommencer=3;
                                test=9;
                        }
                    }

                    }
                   }

    }
    //test fin d jeu
    if(fin!=1)
    {
        for (int k=0 ; k<9 ; k++)
            {
                for (int l=0 ; l<9 ; l++)
                {
                 if(grille[k][l].select==false)
                 test=test+1;
                }
            }
    }

}
while(test!=9 && fin!=1);
// affichage de BRAVO!!
if(recommencer!=3)
{


 SDL_Delay(1000);
 ecran = SDL_SetVideoMode(400, 400, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            position.x = 0;
            position.y = 0;
            SDL_BlitSurface(arrier, NULL, ecran, &position);
            police = TTF_OpenFont("algerien.ttf", 24);
            compteur1=compteur1+compteur2*60;
             sprintf(temps, "Terminee en %d secondes", compteur1);
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, temps,couleur); /* On écrit la chaine temps dans la SDL_Surface */
        position.x = 0;
        position.y = 300;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte contenant le temps */
            position.x = 80;
            position.y = 50;
            SDL_BlitSurface(bravo, NULL, ecran, &position);
            position.x = 0;
            position.y = 170;
            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
            position.x = 170;
            position.y = 170;
            SDL_BlitSurface(quitter, NULL, ecran, &position);
            SDL_Flip(ecran);
            while (recommencer==0 || recommencer==1 || recommencer==2)
            {
            SDL_WaitEvent(&event);
                            switch(event.type)
                                {
                                case SDL_QUIT:
                                return EXIT_SUCCESS;
                                break;
                                case SDL_MOUSEMOTION:
                                        i=event.motion.x;
                                        j=event.motion.y;
                                        if (i<130 && i>0 && j<300 && j>170)
                                        {
                                            recommencer=1;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer2, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        else
                                        {
                                            if (i<300 && i>170 && j<300 && j>170)
                                        {
                                            recommencer=2;
                                        }
                                        else
                                        {
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        }

                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (recommencer== 2)
                        {
                                return EXIT_SUCCESS;
                        }
                        if (recommencer== 2)
                        {
                                recommencer=3;
                        }
                    }

                    }
            }
}

}
//pause

break;


}

case 5:
{

int continuer=1;
fin=0;
test=0;
recommencer=0;
compteur1=0;
compteur2=0;
while (continuer)
{
ecran = SDL_SetVideoMode(LARGEUR_FENETRE+ 5*LMAX, LARGEUR_FENETRE+20+10*LMAX, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
s=0;
fin=0;
test=0;
recommencer=0;
compteur1=0;
compteur2=0;
mines=40;
for (int k=0;k<16;k++)
{
    for (int l=0;l<16;l++)
    {
        grille[k][l].val=0;
        grille[k][l].select = false;
        grille[k][l].choix = 0;
    }
}
while (s<40 )
{

k=rand()%16+0;
l=rand()%16+0;
if (grille[k][l].val!=9)
{
grille[k][l].val=9;
s=s++;
}
}





//void remplir(int **grille)
//{int i,j;

remplir1(grille);

position.x = 0;
position.y = 0;
SDL_BlitSurface(font_jeu, NULL, ecran, &position);

for (int k=0 ; k<16 ; k++)
            {
                for (int l=0 ; l<16 ; l++)
                {
                 position.x = l * 35;
                 position.y = k * 35;
                 SDL_BlitSurface(case_cache, NULL, ecran, &position);
                }
            }
SDL_Flip(ecran);
  /* Chargement de la police */
police = TTF_OpenFont("algerien.ttf", 25);
/* Initialisation du temps et du texte */
tempsActuel = SDL_GetTicks();
sprintf(temps, "%d: %d", compteur2,compteur1);
texte = TTF_RenderText_Solid(police, temps, couleur);

int i=16,j=16,m=16,n=16;
do
{
    test=0;
    do
    {
        SDL_Delay(100);
        CHOI=3;
        SDL_PollEvent(&event);
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 1000) /* Si 1000ms au moins se sont écoulées */
        {
        compteur1+=1;
        if (compteur1==60)
        {
        compteur1=0;
        compteur2 +=1;
        }

        tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }
        sprintf(temps, "Temps %d: %d", compteur2,compteur1); /* On écrit dans la chaîne "temps" le nouveau temps */
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, temps,couleur); /* On écrit la chaine temps dans la SDL_Surface */
        position.x = 160;
        position.y = 590;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        position.x = 100;
        position.y = 590;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte contenant le temps */
        sprintf(mine, "Mines: %d", mines); /* On écrit dans la chaîne "temps" le nouveau temps */
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, mine,couleur);
        position.x = 300;
        position.y = 590;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_Flip(ecran);
        switch(event.type)
            {
                case SDL_QUIT:
                return EXIT_SUCCESS;
            break;
            case SDL_MOUSEMOTION:
                    k=event.motion.y;
                    if (k<30 && k>0)
                    {
                       m=0;
                    }
                    else
                    {
                          if (k<65 && k>35 )
                        {
                            m=1;
                        }
                        else
                        {
                                if (k<100 && k>70)
                            {
                                m=2;
                            }
                            else
                            {
                                    if (k<135 && k>105)
                                {
                                    m=3;
                                }
                                else
                                {
                                        if (k<170 && k>140 )
                                    {
                                        m=4;
                                    }
                                    else
                                    {
                                            if (k<205 && k>175)
                                        {
                                            m=5;
                                        }
                                        else
                                        {
                                                if (k<240 && k>210)
                                            {
                                                m=6;
                                            }
                                            else
                                            {
                                                    if (k<275 && k>245)
                                                {
                                                    m=7;
                                                }
                                                else
                                                {
                                                    if (k<310 && k>280)
                                                {
                                                    m=8;
                                                }
                                                else
                                                {
                                                       if (k<345 && k>315)
                                                    {
                                                        m=9;
                                                    }
                                                    else
                                                    {
                                                        if (k<380 && k>350)
                                                        {
                                                            m=10;
                                                        }
                                                        else
                                                        {
                                                            if (k<415 && k>385)
                                                            {
                                                                m=11;
                                                            }
                                                            else
                                                            {
                                                                if (k<450 && k>420)
                                                                {
                                                                    m=12;
                                                                }
                                                                else
                                                                {
                                                                    if (k<485 && k>455)
                                                                    {
                                                                        m=13;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (k<520 && k>490)
                                                                        {
                                                                            m=14;
                                                                        }
                                                                        else
                                                                        {
                                                                            if (k<555 && k>525)
                                                                            {
                                                                                m=15;
                                                                            }
                                                                            else
                                                                            {
                                                                                m=16;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                }

                                            }

                                        }

                                    }

                                }

                            }

                        }

                    }

                    l=event.motion.x;
                    if (l<30 && l>0)
                    {
                       n=0;
                    }
                    else
                    {
                            if (l<65 && l>35 )
                        {
                            n=1;
                        }
                        else
                        {
                                if (l<100 && l>70)
                            {
                                n=2;
                            }
                            else
                            {
                                    if (l<135 && l>105)
                                {
                                    n=3;
                                }
                                else
                                {
                                        if (l<170 && l>140 )
                                    {
                                        n=4;
                                    }
                                    else
                                    {
                                            if (l<205 && l>175)
                                        {
                                            n=5;
                                        }
                                        else
                                        {
                                                if (l<240 && l>210)
                                            {
                                                n=6;
                                            }
                                            else
                                            {
                                                    if (l<275 && l>245)
                                                {
                                                    n=7;
                                                }
                                                else
                                                {
                                                        if (l<310 && l>280)
                                                    {
                                                        n=8;
                                                    }
                                                    else
                                                {
                                                       if (l<345 && l>315)
                                                    {
                                                        n=9;
                                                    }
                                                    else
                                                    {
                                                        if (l<380 && l>350)
                                                        {
                                                            n=10;
                                                        }
                                                        else
                                                        {
                                                            if (l<415 && l>385)
                                                            {
                                                                n=11;
                                                            }
                                                            else
                                                            {
                                                                if (l<450 && l>420)
                                                                {
                                                                    n=12;
                                                                }
                                                                else
                                                                {
                                                                    if (l<485 && l>455)
                                                                    {
                                                                        n=13;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (l<520 && l>490)
                                                                        {
                                                                            n=14;
                                                                        }
                                                                        else
                                                                        {
                                                                            if (l<555 && l>525)
                                                                            {
                                                                                n=15;
                                                                            }
                                                                            else
                                                                            {
                                                                                n=16;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                }

                                            }

                                        }

                                    }

                                }

                            }

                        }

                    }

                    break;
                case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
{
    if (m<16 && n<16)
    {
       i=m;
       j=n;
       CHOI=0;
       if (grille[m][n].choix==1 && grille[m][n].select==false)
       {
           mines+=1;
       }
    }

}
else
{
    if ( event.button.button == SDL_BUTTON_RIGHT)
    {
       if (m<16 && n<16 && grille[m][n].select==false)
       {
                i=m;
                j=n;
                if (grille[i][j].choix == 0)
                {
                    grille[i][j].choix = 1;
                    mines-=1;
                    CHOI=1;
                    break;
                }
                if (grille[i][j].choix == 1)
                {
                    grille[i][j].choix = 2;
                    mines+=1;
                    CHOI=1;
                    break;
                }
                if (grille[i][j].choix == 2)
                {
                    grille[i][j].choix = 0;
                    CHOI=1;
                    break;
                }

       }
    }
}
break;
    }
    }
    while (i>15 || j>15 || CHOI==3);

    if (grille[i][j].val!=9 &&  CHOI==0)
    {
       jeu1(grille,i,j);
      for (int k=0 ; k<16 ; k++)
            {
            for (int l=0 ; l<16 ; l++)
                {
                    position.x = l * 35;
                    position.y = k * 35;
                 if (grille[k][l].select==true)
                 {
                     switch (grille[k][l].val)
                     {
                         case 0:
                         SDL_BlitSurface(case_vide, NULL, ecran, &position);
                         break;
                         case 1:
                         SDL_BlitSurface(un, NULL, ecran, &position);
                         break;
                         case 2:
                         SDL_BlitSurface(deux, NULL, ecran, &position);
                         break;
                         case 3:
                         SDL_BlitSurface(trois, NULL, ecran, &position);
                         break;
                         case 4:
                         SDL_BlitSurface(quatre, NULL, ecran, &position);
                         break;
                         case 5:
                         SDL_BlitSurface(cinq, NULL, ecran, &position);
                         break;
                         case 6:
                         SDL_BlitSurface(six, NULL, ecran, &position);
                         break;
                         case 7:
                         SDL_BlitSurface(sept, NULL, ecran, &position);
                         break;
                         case 8:
                         SDL_BlitSurface(huit, NULL, ecran, &position);
                         break;
                     }
                 }
                 else
                     {
                            switch (grille[k][l].choix)
                             {
                                 case 0:
                                 SDL_BlitSurface(case_cache, NULL, ecran, &position);
                                 break;
                                 case 1:
                                 SDL_BlitSurface(flag, NULL, ecran, &position);
                                 break;
                                 case 2:
                                 SDL_BlitSurface(interrogation, NULL, ecran, &position);
                                 break;
                             }
                        }
                }
            }
         SDL_Flip(ecran);
    }
    if (CHOI==1)
        {
            for (int k=0 ; k<16 ; k++)
                {
                    for (int l=0 ; l<16 ; l++)
                    {
                        position.x = l * 35;
                        position.y = k * 35;
                        if (grille[k][l].select==false)
                        {
                            switch (grille[k][l].choix)
                             {
                                 case 0:
                                 SDL_BlitSurface(case_cache, NULL, ecran, &position);
                                 break;
                                 case 1:
                                 SDL_BlitSurface(flag, NULL, ecran, &position);
                                 break;
                                 case 2:
                                 SDL_BlitSurface(interrogation, NULL, ecran, &position);
                                 break;
                             }
                        }
                    }
                }
                SDL_Flip(ecran);
        }
            if (grille[i][j].val==9 && CHOI==0)
    {
        fin=1;
        for (int k=0 ; k<16 ; k++)
            {
                for (int l=0 ; l<16 ; l++)
                {
                    position.x = l * 35;
                 position.y = k * 35;
                 if (grille[k][l].val==9)
                 {
                 SDL_BlitSurface(bombe, NULL, ecran, &position);
                 }
                 else
                 {
                     switch (grille[k][l].val)
                     {
                         case 0:
                         SDL_BlitSurface(case_vide, NULL, ecran, &position);
                         break;
                         case 1:
                         SDL_BlitSurface(un, NULL, ecran, &position);
                         break;
                         case 2:
                         SDL_BlitSurface(deux, NULL, ecran, &position);
                         break;
                         case 3:
                         SDL_BlitSurface(trois, NULL, ecran, &position);
                         break;
                         case 4:
                         SDL_BlitSurface(quatre, NULL, ecran, &position);
                         break;
                         case 5:
                         SDL_BlitSurface(cinq, NULL, ecran, &position);
                         break;
                         case 6:
                         SDL_BlitSurface(six, NULL, ecran, &position);
                         break;
                         case 7:
                         SDL_BlitSurface(sept, NULL, ecran, &position);
                         break;
                         case 8:
                         SDL_BlitSurface(huit, NULL, ecran, &position);
                         break;
                     }
                 }
                }
            }
            SDL_Flip(ecran);
            SDL_Delay(1000);
            ecran = SDL_SetVideoMode(400, 400, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

            position.x = 0;
            position.y = 0;
            SDL_BlitSurface(arrier, NULL, ecran, &position);
            position.x = 80;
            position.y = 50;
            SDL_BlitSurface(echec, NULL, ecran, &position);
            position.x = 0;
            position.y = 170;
            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
            position.x = 170;
            position.y = 170;
            SDL_BlitSurface(quitter, NULL, ecran, &position);
            SDL_Flip(ecran);
            int continuer = 1;
            SDL_Event event;
             while (recommencer==0 || recommencer==1 || recommencer==2)
            {
            SDL_WaitEvent(&event);
                            switch(event.type)
                                {
                                case SDL_QUIT:
                                return EXIT_SUCCESS;
                                break;
                                case SDL_MOUSEMOTION:
                                        i=event.motion.x;
                                        j=event.motion.y;
                                        if (i<130 && i>0 && j<300 && j>170)
                                        {
                                            recommencer=1;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer2, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        else
                                        {
                                            if (i<300 && i>170 && j<300 && j>170)
                                        {
                                            recommencer=2;
                                        }
                                        else
                                        {
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        }
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (recommencer== 2)
                        {
                                return EXIT_SUCCESS;
                        }
                        if (recommencer== 1)
                        {
                                recommencer=3;
                                test=40;
                        }
                    }

                    }
                   }

    }

    //test fin d jeu
    for (int k=0 ; k<16 ; k++)
            {
                for (int l=0 ; l<16 ; l++)
                {
                 if(grille[k][l].select==false)
                 test=test+1;
                }
            }
}
while(test!=40 && fin!=1);

// affichage de BRAVO!!
if(recommencer!=3)
{


 SDL_Delay(1000);
 ecran = SDL_SetVideoMode(400, 400, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            police = TTF_OpenFont("algerien.ttf", 30);
            compteur1=compteur1+compteur2*60;
             sprintf(temps, "Terminee en %d secondes", compteur1);
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, temps,couleur); /* On écrit la chaine temps dans la SDL_Surface */
        position.x = 0;
        position.y = 250;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 0,0, 0));
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte contenant le temps */

            position.x = 0;
            position.y = 0;
            SDL_BlitSurface(arrier, NULL, ecran, &position);
            position.x = 80;
            position.y = 50;
            SDL_BlitSurface(bravo, NULL, ecran, &position);
            position.x = 0;
            position.y = 170;
            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
            position.x = 170;
            position.y = 170;
            SDL_BlitSurface(quitter, NULL, ecran, &position);
            SDL_Flip(ecran);
            while (recommencer==0 || recommencer==1 || recommencer==2)
            {
            SDL_WaitEvent(&event);
                            switch(event.type)
                                {
                                case SDL_QUIT:
                                return EXIT_SUCCESS;
                                break;
                                case SDL_MOUSEMOTION:
                                        i=event.motion.x;
                                        j=event.motion.y;
                                        if (i<130 && i>0 && j<300 && j>170)
                                        {
                                            recommencer=1;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer2, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        else
                                        {
                                            if (i<300 && i>170 && j<300 && j>170)
                                        {
                                            recommencer=2;
                                        }
                                        else
                                        {
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        }
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (recommencer== 2)
                        {
                                return EXIT_SUCCESS;
                        }
                        if (recommencer== 2)
                        {
                                recommencer=3;
                        }
                    }

                    }
            }
}

}

break;
}

case 6:
{

int continuer=1;
fin=0;
test=0;
recommencer=0;
while (continuer)
{
ecran = SDL_SetVideoMode(LARGEUR_FENETRE, LARGEUR_FENETRE-210, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
s=0;
fin=0;
test=0;
recommencer=0;
compteur1=0;
compteur2=0;
mines=99;
for (int k=0;k<30;k++)
{
    for (int l=0;l<30;l++)
    {
        grille[k][l].val=0;
        grille[k][l].select = false;
        grille[k][l].choix = 0;
    }
}
while (s<99 )
{

k=rand()%30+0;
l=rand()%30+0;
if (grille[k][l].val!=9)
{
grille[k][l].val=9;
s=s++;
}
}





//void remplir(int **grille)
//{int i,j;

remplir2(grille);

position.x = 0;
position.y = 0;
SDL_BlitSurface(font_jeu, NULL, ecran, &position);
SDL_Flip(ecran);

for (int k=0 ; k<30 ; k++)
            {
                for (int l=0 ; l<30 ; l++)
                {
                 position.x = l * 23;
                 position.y = k * 23;
                 SDL_BlitSurface(case_cache2, NULL, ecran, &position);
                }
            }
SDL_Flip(ecran);
  /* Chargement de la police */
police = TTF_OpenFont("algerien.ttf", 25);
/* Initialisation du temps et du texte */
tempsActuel = SDL_GetTicks();
sprintf(temps, "%d: %d", compteur2,compteur1);
texte = TTF_RenderText_Solid(police, temps, couleur);

int i=30,j=30,m=30,n=30;
do
{
    test=0;
    do
    {
        SDL_Delay(100);
        CHOI=3;
        SDL_PollEvent(&event);
         tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 1000) /* Si 1000ms au moins se sont écoulées */
        {
        compteur1+=1;
        if (compteur1==60)
        {
        compteur1=0;
        compteur2 +=1;
        }
        tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }
        sprintf(temps, "Temps %d: %d", compteur2,compteur1); /* On écrit dans la chaîne "temps" le nouveau temps */
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, temps,couleur); /* On écrit la chaine temps dans la SDL_Surface */
        position.x = 790;
        position.y = 50;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        position.x = 720;
        position.y = 50;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte contenant le temps */
        sprintf(mine, "Mines: %d", mines); /* On écrit dans la chaîne "temps" le nouveau temps */
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, mine,couleur);
        position.x = 720;
        position.y = 200;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_Flip(ecran);
        switch(event.type)
            {
                case SDL_QUIT:
                return EXIT_SUCCESS;
            break;
            case SDL_MOUSEMOTION:
                    k=event.motion.y;
                    if (k<20 && k>0)
                    {
                       m=0;
                    }
                    else
                    {
                          if (k<43 && k>23 )
                        {
                            m=1;
                        }
                        else
                        {
                                if (k<66 && k>46)
                            {
                                m=2;
                            }
                            else
                            {
                                    if (k<89 && k>69)
                                {
                                    m=3;
                                }
                                else
                                {
                                        if (k<112 && k>92 )
                                    {
                                        m=4;
                                    }
                                    else
                                    {
                                            if (k<135 && k>115)
                                        {
                                            m=5;
                                        }
                                        else
                                        {
                                                if (k<158 && k>138)
                                            {
                                                m=6;
                                            }
                                            else
                                            {
                                                    if (k<181 && k>161)
                                                {
                                                    m=7;
                                                }
                                                else
                                                {
                                                    if (k<204 && k>184)
                                                {
                                                    m=8;
                                                }
                                                else
                                                {
                                                       if (k<227 && k>207)
                                                    {
                                                        m=9;
                                                    }
                                                    else
                                                    {
                                                        if (k<250 && k>230)
                                                        {
                                                            m=10;
                                                        }
                                                        else
                                                        {
                                                            if (k<273 && k>253)
                                                            {
                                                                m=11;
                                                            }
                                                            else
                                                            {
                                                                if (k<296 && k>276)
                                                                {
                                                                    m=12;
                                                                }
                                                                else
                                                                {
                                                                    if (k<319 && k>299)
                                                                    {
                                                                        m=13;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (k<342 && k>322)
                                                                        {
                                                                            m=14;
                                                                        }
                                                                        else
                                                                        {
                                                                            if (k<365 && k>345)
                                                                            {
                                                                                m=15;
                                                                            }
                                                                            else{if( k<388 && k>368)
                                                                            {
                                                                                m=16;
                                                                            }
                                                                              else {if( k<411  && k>391)
                                                                              {m=17;
                                                                              }
                                                                               else {if(k>414 && k<434)
                                                                               {m=18;
                                                                               }
                                                                                 else{if(k>437&&k<457)
                                                                                 {m=19;
                                                                                 }
                                                                                   else {if(k>460 &&k<480)
                                                                                   {m=20;
                                                                                   }
                                                                                     else {if(k>483 && k<503  )
                                                                                     {m=21;
                                                                                     }
                                                                                      else {if(k>506 && k<526)
                                                                                      {m=22;
                                                                                      }
                                                                                       else {if(k>529 && k<549)
                                                                                       {m=23;
                                                                                       }
                                                                                        else{ if(k>552 &&k<572)
                                                                                        {m=24;
                                                                                        }
                                                                                         else { if(k>575 &&k<595)
                                                                                         {m=25;
                                                                                         }
                                                                                          else { if (k>598 && k<618)
                                                                                          {m=26;
                                                                                          }
                                                                                           else{ if(k>621 && k<641)
                                                                                           {m=27;
                                                                                           }
                                                                                            else {if(k>644 && k<664)
                                                                                            {m=28;
                                                                                            }
                                                                                             else{
                                                                                             if(k>667 && k<687){m=29;
                                                                                             }
                                                                                              else
                                                                                              {m=30;}

                                                                        }}}}}}}}}}}}}}}
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                }

                                            }

                                        }

                                    }

                                }

                            }

                        }

                    }

                    l=event.motion.x;
                    if (l<20 && l>0)
                    {
                       n=0;
                    }
                    else
                    {
                          if (l<43 && l>23 )
                        {
                            n=1;
                        }
                        else
                        {
                                if (l<66 && l>46)
                            {
                                n=2;
                            }
                            else
                            {
                                    if (l<89 && l>69)
                                {
                                    n=3;
                                }
                                else
                                {
                                        if (l<112 && l>92 )
                                    {
                                        n=4;
                                    }
                                    else
                                    {
                                            if (l<135 && l>115)
                                        {
                                            n=5;
                                        }
                                        else
                                        {
                                                if (l<158 && l>138)
                                            {
                                                n=6;
                                            }
                                            else
                                            {
                                                    if (l<181 && l>161)
                                                {
                                                    n=7;
                                                }
                                                else
                                                {
                                                    if (l<204 && l>184)
                                                {
                                                    n=8;
                                                }
                                                else
                                                {
                                                       if (l<227 && l>207)
                                                    {
                                                        n=9;
                                                    }
                                                    else
                                                    {
                                                        if (l<250 && l>230)
                                                        {
                                                            n=10;
                                                        }
                                                        else
                                                        {
                                                            if (l<273 && l>253)
                                                            {
                                                                n=11;
                                                            }
                                                            else
                                                            {
                                                                if (l<296 && l>276)
                                                                {
                                                                    n=12;
                                                                }
                                                                else
                                                                {
                                                                    if (l<319 && l>299)
                                                                    {
                                                                        n=13;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (l<342 && l>322)
                                                                        {
                                                                            n=14;
                                                                        }
                                                                        else
                                                                        {
                                                                            if (l<365 && l>345)
                                                                            {
                                                                                n=15;
                                                                            }
                                                                            else{if( l<388 && l>368)
                                                                            {
                                                                                n=16;
                                                                            }
                                                                              else {if( l<411  && l>391)
                                                                              {n=17;
                                                                              }
                                                                               else {if(l>414 && l<434)
                                                                               {n=18;
                                                                               }
                                                                                 else{if(l>437&& l<457)
                                                                                 {
                                                                                 n=19;
                                                                                 }
                                                                                   else {if(l>460 && l<480)
                                                                                   {n=20;
                                                                                   }
                                                                                     else {if(l>483 && l<503  )
                                                                                     {n=21;
                                                                                     }
                                                                                      else {if(l>506 && l<526)
                                                                                      {n=22;
                                                                                      }
                                                                                       else {if(l>529 && l<549)
                                                                                       {n=23;
                                                                                       }
                                                                                        else{ if(l>552 &&l<572)
                                                                                        {n=24;
                                                                                        }
                                                                                         else { if(l>575 &&l<595)
                                                                                         {n=25;
                                                                                         }
                                                                                          else { if (l>598 && l<618)
                                                                                          {n=26;
                                                                                          }
                                                                                           else{ if(l>621 && l<641)
                                                                                           {n=27;
                                                                                           }
                                                                                            else {if(l>644 && l<664)
                                                                                            {n=28;
                                                                                            }
                                                                                             else{
                                                                                             if(l>667 && l<687){n=29;
                                                                                             }
                                                                                              else
                                                                                              {m=30;}

                                                                                       }}}}}}}}}}}}}}}
                                                                                      }


                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                }

                                            }

                                        }

                                    }

                                }



                    break;
                case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
{
    if (m<30 && n<30)
    {
       i=m;
       j=n;
       CHOI=0;
       if (grille[m][n].choix==1 && grille[m][n].select==false)
       {
           mines+=1;
       }
    }

}
else
{
    if ( event.button.button == SDL_BUTTON_RIGHT)
    {
       if (m<30 && n<30 && grille[m][n].select==false)
       {
                i=m;
                j=n;
                if (grille[i][j].choix == 0)
                {
                    grille[i][j].choix = 1;
                    mines-=1;
                    CHOI=1;
                    break;
                }
                if (grille[i][j].choix == 1)
                {
                    grille[i][j].choix = 2;
                    mines+=1;
                    CHOI=1;
                    break;
                }
                if (grille[i][j].choix == 2)
                {
                    grille[i][j].choix = 0;
                    CHOI=1;
                    break;
                }

       }
    }
}
break;
    }
    }
    while (i>29 || j>29 || CHOI==3);

    if (grille[i][j].val!=9 && CHOI==0)
    {
       jeu2(grille,i,j);
      for (int k=0 ; k<30 ; k++)
            {
                for (int l=0 ; l<30 ; l++)
                {
                    position.x = l * 23;
                    position.y = k * 23;
                 if (grille[k][l].select==true)
                 {
                     switch (grille[k][l].val)
                     {
                         case 0:
                         SDL_BlitSurface(case_vide2, NULL, ecran, &position);
                         break;
                         case 1:
                         SDL_BlitSurface(unA, NULL, ecran, &position);
                         break;
                         case 2:
                         SDL_BlitSurface(deuxA, NULL, ecran, &position);
                         break;
                         case 3:
                         SDL_BlitSurface(troisA, NULL, ecran, &position);
                         break;
                         case 4:
                         SDL_BlitSurface(quatreA, NULL, ecran, &position);
                         break;
                         case 5:
                         SDL_BlitSurface(cinqA, NULL, ecran, &position);
                         break;
                         case 6:
                         SDL_BlitSurface(sixA, NULL, ecran, &position);
                         break;
                         case 7:
                         SDL_BlitSurface(septA, NULL, ecran, &position);
                         break;
                         case 8:
                         SDL_BlitSurface(huitA, NULL, ecran, &position);
                         break;
                     }
                 }
                 else
                     {
                            switch (grille[k][l].choix)
                             {
                                 case 0:
                                 SDL_BlitSurface(case_cache2, NULL, ecran, &position);
                                 break;
                                 case 1:
                                 SDL_BlitSurface(flag2, NULL, ecran, &position);
                                 break;
                                 case 2:
                                 SDL_BlitSurface(interrogation2, NULL, ecran, &position);
                                 break;
                             }
                        }
                }
            }
         SDL_Flip(ecran);
    }
    if (CHOI==1)
        {
            for (int k=0 ; k<30 ; k++)
                {
                    for (int l=0 ; l<30 ; l++)
                    {
                        position.x = l * 23;
                        position.y = k * 23;
                        if (grille[k][l].select==false)
                        {
                            switch (grille[k][l].choix)
                             {
                                 case 0:
                                 SDL_BlitSurface(case_cache2, NULL, ecran, &position);
                                 break;
                                 case 1:
                                 SDL_BlitSurface(flag2, NULL, ecran, &position);
                                 break;
                                 case 2:
                                 SDL_BlitSurface(interrogation2, NULL, ecran, &position);
                                 break;
                             }
                        }
                    }
                }
                SDL_Flip(ecran);
        }

if (grille[i][j].val==9 && CHOI==0)
    {
        fin=1;
        for (int k=0 ; k<30 ; k++)
            {
                for (int l=0 ; l<30 ; l++)
                {
                    position.x = l * 23;
                 position.y = k * 23;
                 if (grille[k][l].val==9)
                 {
                 SDL_BlitSurface(bombe2, NULL, ecran, &position);
                 }
                 else
                 {
                     switch (grille[k][l].val)
                     {
                         case 0:
                         SDL_BlitSurface(case_vide2, NULL, ecran, &position);
                         break;
                         case 1:
                         SDL_BlitSurface(unA, NULL, ecran, &position);
                         break;
                         case 2:
                         SDL_BlitSurface(deuxA, NULL, ecran, &position);
                         break;
                         case 3:
                         SDL_BlitSurface(troisA, NULL, ecran, &position);
                         break;
                         case 4:
                         SDL_BlitSurface(quatreA, NULL, ecran, &position);
                         break;
                         case 5:
                         SDL_BlitSurface(cinqA, NULL, ecran, &position);
                         break;
                         case 6:
                         SDL_BlitSurface(sixA, NULL, ecran, &position);
                         break;
                         case 7:
                         SDL_BlitSurface(septA, NULL, ecran, &position);
                         break;
                         case 8:
                         SDL_BlitSurface(huitA, NULL, ecran, &position);
                         break;
                     }
                 }
                }
            }
            SDL_Flip(ecran);
            SDL_Delay(1000);
            ecran = SDL_SetVideoMode(400, 400, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

            position.x = 0;
            position.y = 0;
            SDL_BlitSurface(arrier, NULL, ecran, &position);
            position.x = 80;
            position.y = 50;
            SDL_BlitSurface(echec, NULL, ecran, &position);
            position.x = 0;
            position.y = 170;
            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
            position.x = 170;
            position.y = 170;
            SDL_BlitSurface(quitter, NULL, ecran, &position);
            SDL_Flip(ecran);
            int continuer = 1;
            SDL_Event event;
             while (recommencer==0 || recommencer==1 || recommencer==2)
            {
            SDL_WaitEvent(&event);
                            switch(event.type)
                                {
                                case SDL_QUIT:
                                return EXIT_SUCCESS;
                                break;
                                case SDL_MOUSEMOTION:
                                        i=event.motion.x;
                                        j=event.motion.y;
                                        if (i<130 && i>0 && j<300 && j>170)
                                        {
                                            recommencer=1;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer2, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        else
                                        {
                                            if (i<300 && i>170 && j<300 && j>170)
                                        {
                                            recommencer=2;
                                        }
                                        else
                                        {
                                            recommencer=0;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        }
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (recommencer== 2)
                        {
                                return EXIT_SUCCESS;
                        }
                        if (recommencer== 1)
                        {
                                recommencer=3;
                                test=99;
                        }
                    }

                    }
                   }

    }
    //test fin d jeu
    if(fin!=1)
    {
        for (int k=0 ; k<30 ; k++)
            {
                for (int l=0 ; l<30 ; l++)
                {
                 if(grille[k][l].select==false)
                 test=test+1;
                }
            }
    }

}
while(test!=99 && fin!=1);

// affichage de BRAVO!!
if(recommencer!=3)
{


 SDL_Delay(1000);
 ecran = SDL_SetVideoMode(400, 400, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

            police = TTF_OpenFont("algerien.ttf", 35);
            compteur1=compteur1+compteur2*60;
             sprintf(temps, "Terminee en %d secondes", compteur1);
        SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
        texte = TTF_RenderText_Solid(police, temps,couleur); /* On écrit la chaine temps dans la SDL_Surface */
        position.x = 0;
        position.y = 250;
        SDL_FillRect(ecran, &position, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte contenant le temps */
            position.x = 0;
            position.y = 0;
            SDL_BlitSurface(arrier, NULL, ecran, &position);
            position.x = 80;
            position.y = 50;
            SDL_BlitSurface(bravo, NULL, ecran, &position);
            position.x = 0;
            position.y = 170;
            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
            position.x = 170;
            position.y = 170;
            SDL_BlitSurface(quitter, NULL, ecran, &position);
            SDL_Flip(ecran);
            while (recommencer==0 || recommencer==1 || recommencer==2)
            {
            SDL_WaitEvent(&event);
                            switch(event.type)
                                {
                                case SDL_QUIT:
                                return EXIT_SUCCESS;
                                break;
                                case SDL_MOUSEMOTION:
                                        i=event.motion.x;
                                        j=event.motion.y;
                                        if (i<130 && i>0 && j<300 && j>170)
                                        {
                                            recommencer=1;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer2, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        else
                                        {
                                            if (i<300 && i>170 && j<300 && j>170)
                                        {
                                            recommencer=2;
                                        }
                                        else
                                        {
                                            recommencer=0;
                                            position.x = 0;
                                            position.y = 170;
                                            SDL_BlitSurface(rejouer1, NULL, ecran, &position);
                                            SDL_Flip(ecran);
                                        }
                                        }
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (recommencer== 2)
                        {
                                return EXIT_SUCCESS;
                        }
                        if (recommencer== 2)
                        {
                                recommencer=3;
                        }
                    }

                    }
            }
}

}
//pause
break;


}




/*case 6:
{cout<<endl;
cout<<endl;
cout<<endl;
s=0;
while (s<99 )
{

k=rand()%30+0;
l=rand()%30+0;
if (grille[k][l].val!=9)
{

grille[k][l].val=9;
s=s++;
}
}


for(i=0;i<30;i++)
{


for (j=0; j<30; j++)
{
if (grille[i][j].val==9)
cout<<"*";
else
cout<< grille[i][j].val;

}
cout<<endl;


}


cout <<"---------------------------------------La numerotation de la grille------------------------------------------"<<"\n";
 remplir2(grille);
 cout<<endl;
cout<<endl;
cout<<endl;

cout<<"resultat"<<"\n";
for (w=0;w<30;w++)
{
for (x=0;x<30;x++)
{
if (grille[w][x].val==9)
cout<< "*";
else
cout<<grille[w][x].val;
}

cout<<endl;
}

affichage2(grille);
int i,j;
do
{
    test=0;
    do
    {
        cout<<"saisir l'abcisse de la case choisie:    ";
        cin>>i;
    }
    while (i>30 || i<0);
    do
    {
       cout<<"saisir l'oordonnee de la case choisie:    ";
       cin>>j;
    }
    while (j>30 || j<0);
    if (grille[i][j].val==9)
    {
        fin=1;
        cout<<endl<<"                    JEU FINI!!"<<endl<< "               tu as choisi une BOMBE :O"<<endl;
        for (int k=0 ; k<30 ; k++)
            {
                for (int l=0 ; l<30 ; l++)
                {
                 if (grille[k][l].val==9)
                 {
                     cout<<"(*)";
                 }
                 else
                 {
                     cout<<grille[k][l].val;
                 }
                }
                cout<<endl;
            }

    }
    else
    {
       jeu2(grille,i,j);
    affichage2(grille);
    }
    //test fin d jeu
    for (int k=0 ; k<30 ; k++)
            {
                for (int l=0 ; l<30 ; l++)
                {
                 if(grille[k][l].select==false)
                 test=test+1;
                }
            }
}
while(test!=10 && fin!=1);
break;





}*/
}}


void remplir(cellule **grille)
{int i,j;

for (i=0;i<9;i++)

{
for (j=0;j<9;j++)
{//if (grille[i][j]==9)
while(grille[i][j].val==9)
//if(grille[i][j]==9)



{
    {if (grille[i][j-1].val!=9)
         {

         if(j-1>=0)
     {++(grille[i][j-1].val);}}
    //else
    //break
    }
if (j+1<9)
{if(grille[i][j+1].val!=9)
{++(grille[i][j+1].val);}}
//else break;

{if (i+1<9)
{if (grille[i+1][j].val!=9)
{++(grille[i+1][j].val);}}
//else break;
}

{if(i-1>=0)
{if (grille[i-1][j].val!=9)
{++(grille[i-1][j].val);}}
//else break;
}


     {if (j+1<9)
     {if(i+1<9)
{if (grille[i+1][j+1].val!=9)

{++(grille[i+1][j+1].val);}}}
//else break;
}


{if (j-1>=0)
{if(i+1<9)
{if (grille[i+1][j-1].val!=9)

{
++(grille[i+1][j-1].val);}}}
//else break;
}

{if(j+1<9)
 {if(i-1>=0)
{if (grille[i-1][j+1].val!=9)

{++(grille[i-1][j+1].val);}}
}
//else break;
}

{if(j-1>=0)
{if(i-1>=0)
{if (grille[i-1][j-1].val!=9)

{++(grille[i-1][j-1].val);}}}
//else break;
}
//while((i=9)&&(j=9));
break;
}


}}}
void remplir1(cellule**grille)
{int i,j;
    for (i=0;i<16;i++)
{
for (j=0;j<16;j++)
{//if (grille[i][j]==9)
while(grille[i][j].val==9)
//if(grille[i][j]==9)



{
    {if (grille[i][j-1].val!=9)
         {

         if(j-1>=0)
     {++(grille[i][j-1].val);}}
    //else
    //break
    }

{if (j+1<16)
{if(grille[i][j+1].val!=9)
{++(grille[i][j+1].val);}}
//else break;
}

{if (i+1<16)
{if (grille[i+1][j].val!=9)

{++(grille[i+1][j].val);}}
//else break;
}

{if(i-1>=0)
{if (grille[i-1][j].val!=9)
{++(grille[i-1][j].val);}}
}

{if (j+1<16)
     {if(i+1<16)
{if (grille[i+1][j+1].val!=9)

{++(grille[i+1][j+1].val);}}}

}

{

if (j-1>=0)
{if (grille[i+1][j-1].val!=9)

{


if(i+1<16)
{++(grille[i+1][j-1].val);}}}

}

{if(j+1<16)
 {if(i-1>=0)
{if (grille[i-1][j+1].val!=9)

{++(grille[i-1][j+1].val);}}
}
}

{if(j-1>=0)
{if(i-1>=0)
{if (grille[i-1][j-1].val!=9)

{++(grille[i-1][j-1].val);}}}

}

break;
}


}}}


void remplir2(cellule**grille)
{int i,j;
for (i=0;i<30;i++)
{
for (j=0;j<30;j++)
{
while(grille[i][j].val==9)




{
{if(j-1>=0)
{

if (grille[i][j-1].val!=9)



{++(grille[i][j-1].val);}}
}

{if (j+1<30)
{
if(grille[i][j+1].val!=9)

{++(grille[i][j+1].val);}}
}
{if (i+1<30)
{if (grille[i+1][j].val!=9)

{++(grille[i+1][j].val);}}
}
{if(i-1>=0)
{if (grille[i-1][j].val!=9)

{++(grille[i-1][j].val);}}
//else break;
}
{if ((j+1<30)&&(i+1<30))



{if (grille[i+1][j+1].val!=9)



{++(grille[i+1][j+1].val);}}}


{if ((j-1>=0)&&(i+1<30))

{if (grille[i+1][j-1].val!=9)
{
{++(grille[i+1][j-1].val);}}}
//else break;
}
{if((j+1<30)&&(i-1>=0))
{if (grille[i-1][j+1].val!=9)

{++(grille[i-1][j+1].val);}
}
}
{if((j-1>=0)&&(i-1>=0))
{if (grille[i-1][j-1].val!=9)

{++(grille[i-1][j-1].val);}}
}
break;
}


}}}





void jeu(cellule **grille,int i,int j)
{


    if(grille[i][j].val!=9 && grille[i][j].val!=0 && grille[i][j].select!=true)
    {
        grille[i][j].select=true;

    }
    if (grille[i][j].val==0 && grille[i][j].select!=true)
    {
        grille[i][j].select=true;
        if (i>0)   //case dessus
        {
            jeu(grille,i-1,j);
        }
        if (i<8)    //case dessous
        {
            jeu(grille,i+1,j);
        }
        if (j>0)    //case gauche
        {
            jeu(grille,i,j-1);
        }
        if (j<8)    //case droite
        {
            jeu(grille,i,j+1);
        }
        if (i>0 && j<8)
        {
            jeu(grille,i-1,j+1);
        }
        if (i<8 && j<8)
        {
            jeu(grille,i+1,j+1);
        }
        if (i<8 && j>0)
        {
            jeu(grille,i+1,j-1);
        }
        if (i>0 && j>0)
        {
            jeu(grille,i-1,j-1);
        }

    }


}

void jeu1(cellule **grille,int i,int j)
{


    if(grille[i][j].val!=9 && grille[i][j].val!=0 && grille[i][j].select!=true)
    {
        grille[i][j].select=true;

    }
    if (grille[i][j].val==0 && grille[i][j].select!=true)
    {
        grille[i][j].select=true;
        if (i>0)   //case dessus
        {
            jeu1(grille,i-1,j);
        }
        if (i<15)    //case dessous
        {
            jeu1(grille,i+1,j);
        }
        if (j>0)    //case gauche
        {
            jeu1(grille,i,j-1);
        }
        if (j<15)    //case droite
        {
            jeu1(grille,i,j+1);
        }
        if (i>0 && j<15)
        {
            jeu1(grille,i-1,j+1);
        }
        if (i<15 && j<15)
        {
            jeu1(grille,i+1,j+1);
        }
        if (i<15 && j>0)
        {
            jeu1(grille,i+1,j-1);
        }
        if (i>0 && j>0)
        {
            jeu1(grille,i-1,j-1);
        }

    }


}

void jeu2(cellule **grille,int i,int j)
{


    if(grille[i][j].val!=9 && grille[i][j].val!=0 && grille[i][j].select!=true)
    {
        grille[i][j].select=true;

    }
    if (grille[i][j].val==0 && grille[i][j].select!=true)
    {
        grille[i][j].select=true;
        if (i>0)   //case dessus
        {
            jeu2(grille,i-1,j);
        }
        if (i<29)    //case dessous
        {
            jeu2(grille,i+1,j);
        }
        if (j>0)    //case gauche
        {
            jeu2(grille,i,j-1);
        }
        if (j<29)    //case droite
        {
            jeu2(grille,i,j+1);
        }
        if (i>0 && j<29)
        {
            jeu2(grille,i-1,j+1);
        }
        if (i<29 && j<29)
        {
            jeu2(grille,i+1,j+1);
        }
        if (i<29 && j>0)
        {
            jeu2(grille,i+1,j-1);
        }
        if (i>0 && j>0)
        {
            jeu2(grille,i-1,j-1);
        }

    }


}

