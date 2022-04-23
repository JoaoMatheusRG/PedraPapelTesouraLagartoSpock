/******************************************************************************
Escreva um programa que implemente o jogo conhecido como pedra-papel-tesoura-lagartoSpock
(https://pt.wikipedia.org/wiki/Pedra-papel-tesoura-lagarto-Spock)
Neste jogo, o usuário e o computador escolhem entre pedra, papel, tesoura, lagarto ou Spock.
Sabendo que:
• Tesoura corta papel
• Papel cobre pedra
• Pedra esmaga lagarto
• Lagarto envenena Spock
• Spock esmaga (ou derrete) tesoura
• Tesoura decapita lagarto
• Lagarto come papel
• Papel refuta Spock
• Spock vaporiza pedra
• Pedra amassa tesoura
Exiba na tela o ganhador: usuário ou computador.
Para esta implementação, assuma que o caractere D representa pedra, P representa papel, T
representa tesoura, L representa lagarto e S representa Spock.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>//usada para permitir a acentuaÃ§Ã£o

int maquina ();
int ganhador(int x);
int imprimeganhador(int g,int x,int m);

int maquina(){
    int num;
    
    srand(time(NULL));
    num=1+rand()%5;
    if(num==1){num=84;}
    else if(num==2){num=80;}
    else if(num==3){num=68;}
    else if(num==4){num=76;}
    else{num=83;}
    
    return num;
}
int ganhador(int x){

    int ganhador,y;
    y=maquina();
    
    //para x(usuario)
    if(x==84&&y==80){ganhador=11;}//Tesoura ganha Papel
    if(x==84&&y==76){ganhador=12;}//Tesoura ganha Lagarto
    
    if(x==80&&y==68){ganhador=21;}//Papel ganha Pedra
    if(x==80&&y==83){ganhador=22;}//Papel ganha Spock
    
    if(x==68&&y==76){ganhador=31;}//Pedra ganha Lagarto
    if(x==68&&y==84){ganhador=32;}//Pedra ganha Tesoura
    
    if(x==76&&y==83){ganhador=41;}//Lagarto ganha Spock
    if(x==76&&y==80){ganhador=42;}//Lagarto ganha Papel
    
    if(x==83&&y==84){ganhador=51;}//Spock ganha Tesoura
    if(x==83&&y==68){ganhador=52;}//Spock ganha Pedra
    
    //para y(maquina)
    if(y==84&&x==80){ganhador=61;}//Tesoura ganha Papel
    if(y==84&&x==76){ganhador=62;}//Tesoura ganha Lagarto
    
    if(y==80&&x==68){ganhador=71;}//Papel ganha Pedra
    if(y==80&&x==83){ganhador=72;}//Papel ganha Spock
    
    if(y==68&&x==76){ganhador=81;}//Pedra ganha Lagarto
    if(y==68&&x==84){ganhador=82;}//Pedra ganha Tesoura
    
    if(y==76&&x==83){ganhador=91;}//Lagarto ganha Spock
    if(y==76&&x==80){ganhador=92;}//Lagarto ganha Papel
    
    if(y==83&&x==84){ganhador=101;}//Spock ganha Tesoura
    if(y==83&&x==68){ganhador=102;}//Spock ganha Pedra
    
    
    return ganhador;
}
int imprimeganhador(int g,int x,int m){
      setlocale(LC_ALL, "Portuguese");
    if(x==m){printf("\nQue coincidência!!Você e o computador pensaram igual. Deu empate!!\n");}
    else{
    //usuario ganha    
    if(g>=11&&g<=52){printf("\n         Parabéns Usuário!!! ");}
    if(g==11){printf("A sua Tesoura cortou o Papel ");}//Tesoura ganha Papel
    if(g==12){printf("A sua Tesoura decapitou o Lagarto ");}//Tesoura ganha Lagarto
    
    if(g==21){printf("O seu Papel cobriu a Pedra ");}//Papel ganha Pedra
    if(g==22){printf("O seu Papel refutou o Spock ");}//Papel ganha Spock
    
    if(g==31){printf("A sua Pedra esmagou o Lagarto ");}//Pedra ganha Lagarto
    if(g==32){printf("A sua Pedra amassou a Tesoura ");}//Pedra ganha Tesoura
    
    if(g==41){printf("O seu Lagarto envenenou o Spock ");}//Lagarto ganha Spock
    if(g==42){printf("O seu Lagarto comeu o Papel ");}//Lagarto ganha Papel
    
    if(g==51){printf("O seu Spock derreteu a Tesoura ");}//Spock ganha Tesoura
    if(g==52){printf("O seu Spock vaporizou a Pedra ");}//Spock ganha Pedra
     if(g>=11&&g<=52){printf("do adversário.\t\n");}
    
    
    
    //maquina ganha
    if(g>=61&&g<=102){printf("\n         :( Que pena Usuário!! ");}
    if(g==61){printf("A Tesoura do adversário cortou o seu Papel.\t\n");}//Tesoura ganha Papel
    if(g==62){printf("A Tesoura do adversário decapitou o seu Lagarto.\t\n");}//Tesoura ganha Lagarto
    
    if(g==71){printf("O Papel do adversário cobriu a sua Pedra.\t\n");}//Papel ganha Pedra
    if(g==72){printf("O Papel do adversário refutou o sua Spock.\t\n");}//Papel ganha Spock
    
    if(g==81){printf("A Pedra do adversário esmagou o seu Lagarto.\t\n");}//Pedra ganha Lagarto
    if(g==82){printf("A Pedra do adversário amassou a sua Tesoura.\t\n");}//Pedra ganha Tesoura
    
    if(g==91){printf("O Lagarto do adversário envenenou o seu Spock\t\n");}//Lagarto ganha Spock
    if(g==92){printf("O Lagarto do adversário comeu o seu Papel\t\n");}//Lagarto ganha Papel
    
    if(g==101){printf("O Spock do adversário derreteu a sua Tesoura.\t\n");}//Spock ganha Tesoura
    if(g==102){printf("O Spock do adversário vaporizou a sua Pedra.\t\n");}//Spock ganha Pedra
    }

}
int main()
{
    setlocale(LC_ALL, "Portuguese");//usada junto com o #include <locale.h> para permitir a escrita de caracteres especiais e acentos
    int x,m,g,j=1;
    
    while(j==1){
	
    printf("\n************************** Pedra - Papel - Tesoura - Lagarto - Spock **************************\n\n");
    printf("                                 |============================|\n");
	printf("                                 |      Suas opções são:      |\n");
	printf("                                 |============================|\n");
    printf("                                 |        T - Tesoura         |\n");
    printf("                                 |        P - Papel           |\n");
    printf("                                 |        D - Pedra           |\n");
    printf("                                 |        L - Lagarto         |\n");
    printf("                                 |        S - Spock           |\n");
    printf("                                 |============================|\n");
	printf("\nDigite a letra correspondente a sua opção : ");
   			 x=getchar();
   			 
    while((x!=83)&&(x!=80)&&(x!=68)&&(x!=76)&&(x!=84)){
         do{
        printf("Opa!! Você digitou algo que não faz parte das suas opções. Digite novamente: ");
        }while( getchar() != '\n' );//evita que o getchar pegue o '\n' armazenado anteriormente
        x=getchar();
    
}

    g=ganhador(x);
    m=maquina();
    imprimeganhador(g,x,m);
printf("\n**************************************** Fim de Jogo ******************************************\n");
   do{
   
    printf("\nPressione 1 para jogar novamente.\n");
    printf("Pressione 0 para sair do jogo.\n");
    scanf("%d",&j);
    }while(j>1||j<0);
    do{
    }while( getchar() != '\n' );//para quando o jogo reiniciar, nÃ£o ler '\n' armazenado no Ãºltimo getchar()
}
    return 0;
}
