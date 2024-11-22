#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
main()
{
	//Variables para la primera parte del curso:
	int circuito,programa,n,j,regresar,inicio;
	j=1;
	float rt,VT,R,RT,IT;
	R=0;
	RT=0;
	
	//Variables solucion de ecuaciones:
	int i,k;
	float factor,suma,a[30][30],b[30],x[30];
	
	//Variables señal signoidal
	int wt[37],angle=0;
	float Vmax,v[37];
	
	//Variables para impedancia
	int c;
	float YT,ZT,xl,XL=0,C,xc,XC=0,r,L,ang;
	
	//Inicio
	printf("1870294 Alan Dario Morales Rodriguez");
	printf("\nSolucion de circuitos electricos");
	inicio=1;
	while (inicio==1)
	{
	printf("\n\n				MENU\n		ELIGE LA OPCION QUE DESEES RESOLVER");
	printf("\n\nCORRIENTE DIRECTA: \nCorriente de circuito en serie--------1 \nCorriente de circuito en paralelo-----2 \nCorriente en circuito mixto-----------3 \nCorriente de un circuito de malla real por resolucion de ecuaciones---4");
	printf("\n\nCORRIENTE ALTERNA: \nTabla de la senal signoidal---------------------------------------5 \nImpedancia en serie o paralelo------------------------------------6	");
	scanf("%d",&programa);
	switch(programa)
	{
		case 1:
				j=1;
				printf("\nPROGRAMA QUE CALCULA LA INTENSIDAD DE CORRIENTE TOTAL DE UN CIRCUITO EN SERIE");
				printf("\n\nEscribe el numero de resistencias existentes: ");
				scanf("%d",&n);
				while(j<=n)
				{
				printf("Dame el valor de la resistencia %d: ",j);
				scanf("%f",&rt);
				RT=rt+RT;
				j=j+1;	
				}
				printf("Dame el valor del voltaje total: ");
				scanf("%f",&VT); 
				IT=VT/RT;
				printf("CORRIENTE TOTAL = %.2f A",IT);
				break;
		case 2: 
				j=1;
				printf("\nPROGRAMA QUE CALCULA LA INTENSIDAD DE CORRIENTE TOTAL DE UN CIRCUITO EN PARALELOP");
				printf("\n\nEscribe el numero de resistencias existentes: ");
				scanf("%d",&n);
				while(j<=n)
				{
				printf("Dame el valor de la resistencia %d: ",j);
				scanf("%f",&rt);
				R=1/rt+R;
				j=j+1;	
				}
				RT=1/R;
				printf("Dame el valor del voltaje total: ");
				scanf("%f",&VT);
				IT=VT/RT;
				printf("CORRIENTE TOTAL = %.2f A",IT);
				break;
		case 3:
			
				printf("\nPROGRAMA QUE CALCULA LA INTENSIDAD DE CORRIENTE TOTAL DE UN CIRCUITO MIXTO");
				regresar=1;
				while (regresar==1)
				{      
					printf("\n\nSelecciona las resistencias a calcular: \nResistencias en serie------1 \nResistencias en paralelo---2 \n");
					scanf("%d",&circuito);
					switch(circuito)
					{
						case 1:
								j=1;
								R=0;
								printf("\nEscribe la cantidad de resistencias en serie: ");
								scanf("%d",&n);
								while(j<=n)
								{
								printf("Dame el valor de la resistencia %d: ",j);
								scanf("%f",&rt);
								R=rt+R;
								j=j+1;
								}
								R=R+RT;
								break;
						case 2:
								j=1;
								R=0;
								printf("\nEscribe la cantidad de resistencias en paralelo: ");
								scanf("%d",&n);
								while(j<=n)
								{
								printf("Dame el valor de la resistencia %d: ",j);
								scanf("%f",&rt);
								R=1/rt+R;
								j=j+1;
								}
								R=R+1/RT;
								R=1/R;
								break;
					}
					RT=R;
					printf("\n¿Desea agregar resistencias mas? Si=1, No=0  ");
					scanf("%d",&regresar);
				}
				printf("\nLa resistencia total es: %.2f",RT);
				printf("\nIngrese el valor del voltaje total: ");
				scanf("%f",&VT);
				IT=VT/RT;
				printf("CORRIENTE TOTAL = %.2f A",IT);
				break;
		case 4:
				printf("\nPROGRAMA QUE RESUELVE LAS ECUACIONES DE CORRIENTES DE UN CIRCUITO DE MALLA REAL POR EL METODO DE ELIMINACION GAUSSIANA");
				printf("\n\nIngrese el numero de ecuaciones: ");
				scanf("%d",&n);
				printf("\nIngrese los coeficientes de las variables:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("\nIngrese los terminos independientes:\n");
				for(i=0;i<n;i++)
				{
					scanf("%f",&b[i]);
				}
				for(k=0;k<n-1;k++)
				{
					for(i=k+1;i<n;i++)
					{
						factor=a[i][k]/a[k][k];
						for(j=k;j<n;j++)
						{
							a[i][j]=a[i][j]-factor*a[k][j];
						}
						b[i]=b[i]-factor*b[k];
					}
				}
				x[n-1]=b[n-1]/a[n-1][n-1];
				for(i=n-2;i>=0;i--)
				{
					suma=b[i];
					for(j=i+1;j<n;j++)
					{
						suma=suma-a[i][j]*x[j];
					}
					x[i]=suma/a[i][i];
				}
				printf("\SOLUCION:\n");
				for(i=0;i<n;i++)
				{
					printf("\nI%d = %.2f A",i+1,x[i]);
				}
				break;
		case 5:
				printf("\nPROGRAMA QUE IMPRIME LA TABLA DE LA CORRIENTE ALTERNA SENOIDAL");
				printf("\n\nDame el voltaje maximo: ");
				scanf("%f",&Vmax);
				for(i=1;i<=37;i++)
				{
					v[i]=Vmax*sin(angle*M_PI/180);
					wt[i]=angle;
					angle=angle+10;
				}
				printf("\n	wt		V");
				for(i=1;i<=37;i++)
				{
					printf("\n	%d		%.2f",wt[i],v[i]);
				}
				break;
		case 6:
				printf("\n\nPROGRAMA QUE CALCULA LA IMPEDANCIA TOTAL DE UN CIRCUITO EN SERIE O PARALELO");
				printf("\n\nElije el circuito que deseas calcular la impedancia: \nEn serie------1 \nEn paralelo---2\n");
				scanf("%d",&c);
				switch(c)
				{
				case 1:
					R=0;
					XC=0;
					XL=0;
					printf("\nEscribe el numero de resistencias que hay: ");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
					printf("Dame el valor de la resistencia %d: ",i);
					scanf("%f",&r);
					R=r+R;
					}
					printf("\nEscribe el numero de bobinas que hay: ");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
					printf("Dame el valor de la inductancia %d en MILI henrios: ",i);
					scanf("%f",&L);
					xl=60*2*M_PI*L/1000;
					XL=xl+XL;
					}
					printf("\nEscribe el numero de capacitores que hay: ");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
					printf("Dame el valor de la capacitancia %d en MICRO faradios: ",i);
					scanf("%f",&C);
					xc=1/(60*2*M_PI*C/1000000);
					XC=xc+XC;
					}
					ZT=sqrt(R*R+(XL-XC)*(XL-XC));
					ang=180*(atan((XL-XC)/R))/M_PI;
					printf("\nIMPEDANCIA TOTAL = %.4f angle %.4f OHMS",ZT,ang);
					break;
				case 2:
					R=0;
					XL=0;
					XC=0;
					printf("\nEscribe el numero de resistencias que hay: ");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
					printf("Dame el valor de la resistencia %d: ",i);
					scanf("%f",&r);
					R=1/r+R;
					}
					printf("\nEscribe el numero de bobinas que hay: ");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
					printf("Dame el valor de la inductancia %d en MILI henrios: ",i);
					scanf("%f",&L);
					xl=60*2*M_PI*L/1000;
					XL=1/xl+XL;
					}
					printf("\nEscribe el numero de capacitores que hay: ");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
					printf("Dame el valor de la capacitancia %d en MICRO faradios: ",i);
					scanf("%f",&C);
					xc=1/(60*2*M_PI*C/1000000);
					XC=1/xc+XC;
					}
					YT=sqrt(R*R+(XL-XC)*(XL-XC));
					ZT=1/YT;
					ang=180*(atan((XL-XC)/R))/M_PI;
					printf("\nIMPEDANCIA TOTAL = %.4f angle %.4f OHMS",ZT,ang);
					break;			
				}
	}
	printf("\n\n¿Desea utilizar otro programa? Si=1, No=0  ");
	scanf("%d",&inicio);
	system("cls");
	}
	getche();
}
