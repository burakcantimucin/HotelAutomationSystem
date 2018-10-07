#include <stdio.h>
#include <stdlib.h>

int main()
{
    float on_odeme, havale, normal_odeme, ucret;
    char tamam_ya_da_devam, *mevsim_kontrol, mevsim, oda_tipi, ucret_sekli;
    int misafir_degiskeni, toplam_kisi, hafta, i=1, j, misafir, misafir_sayac=1, digermisafir_odanumara[100], oda_numara, oda_numara_sayac=0, oda_numara_kontrol=-1, hafta_sayac=0, oda_sayisi[100];
    do
    {
    printf("Hangi mevsimde konaklama yapmak istersiniz?\n");
    printf("Sonbahar icin 'S', Bahar icin 'B', Yaz icin 'Y' kodunu giriniz: ");
    scanf("%c",&mevsim);
    switch(mevsim)
    {
    case 'S':
    {
        mevsim_kontrol="Sonbahar";
        do
        {
            printf("\nSonbahar ayinin kacinci haftasinda konaklama yapilacagini giriniz: ");
            scanf("%d",&hafta);
            fflush(stdin);
            if(hafta<1 || hafta>12)
            {
                hafta_sayac++;
            }
            if(hafta_sayac==3)
            {
                printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                exit(0);
            }
        }
        while(hafta<1 || hafta>12);
        printf("\nLutfen oda tipini seciniz.\nStandart oda icin 'S', Deluxe oda icin 'D', Large Deluxe oda icin 'L' kodunu giriniz: ");
        scanf("%c",&oda_tipi);if (oda_tipi=='S')
        {
            printf("\n");
            for(i=0;i<=100;i++)
            {
                if (i%2==0)
                    continue;
                oda_sayisi[i]=i;
                printf("%d",oda_sayisi[i]);
                if (i!=99)
                    printf("---");
            }
            printf(" nolu odalar Standart odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=0;j<=100;j++)
                {
                    if (j%2==0 || j==0)
                        continue;
                    if (j%2==1)
                        oda_sayisi[j]=j;
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklanacak: ");
            scanf("%d",&misafir);
            misafir_degiskeni=misafir;
            if(misafir<=4)
                toplam_kisi=1;
            if(misafir>4)
            {
                while(misafir>4)
                {
                     misafir-=4;
                     misafir_sayac++;
                }
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                        while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || (digermisafir_odanumara[toplam_kisi]%2==0))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%2==0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                        toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=25*misafir_degiskeni;
        }
        else if (oda_tipi=='D')
        {
            printf("\n");
            for(i=0;i<=100;i++)
            {
                if (i%6!=0 && i%2==0)
                {
                    if(i==0)
                        break;
                    oda_sayisi[i]=i;
                    printf("%d",oda_sayisi[i]);
                    if ((i+2)!=102)
                        printf("---");
                }
            }
            printf(" nolu odalar Deluxe odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=0;j<=100;j++)
                {
                    if (j%6!=0 || j%2==0)
                    {
                        oda_sayisi[j]=j;
                    }
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklanacak: ");
            scanf("%d",&misafir);
            misafir_degiskeni=misafir;
            if(misafir<=4)
                toplam_kisi=1;
            if(misafir>4)
            {
                do
                {
                     misafir-=4;
                     misafir_sayac++;
                }
                while(misafir>4);
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                        while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || ((digermisafir_odanumara[toplam_kisi]%2!=0 || digermisafir_odanumara[toplam_kisi]%6==0)))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%2!=0 || digermisafir_odanumara[toplam_kisi]%6==0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                        toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=50*misafir_degiskeni;
        }
        else if (oda_tipi=='L')
        {
            printf("\n");
            for(i=0;i<=100;i++)
            {
                if (i%6==0)
                {
                    if (i==0)
                        continue;
                    oda_sayisi[i]=i;
                    printf("%d",oda_sayisi[i]);
                    if (i!=96)
                printf("---");
                }
            }
            printf(" nolu odalar Large Deluxe odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=0;j<100;j++)
                {
                    if (j%6==0)
                    {
                        oda_sayisi[j]=j;
                    }
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklayacak: ");
            scanf("%d",&misafir);
            if(misafir<=7)
                toplam_kisi=1;
            else if(misafir>7)
            {
                do
                {
                     misafir-=7;
                     misafir_sayac++;
                }
                while(misafir>7);
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                    while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || (digermisafir_odanumara[toplam_kisi]%6!=0))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%6!=0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                    toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=250*misafir_sayac;
        }
        break;
    }
    case 'B':
    {
        mevsim_kontrol="Bahar";
        do
        {
            printf("\nBahar ayinin kacinci haftasinda konaklama yapilacagini giriniz: ");
            scanf("%d",&hafta);
            fflush(stdin);
            if(hafta<1 || hafta>12)
            {
                hafta_sayac++;
            }
            if(hafta_sayac==3)
            {
                printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                exit(0);
            }
        }
        while(hafta<1 || hafta>12);
        printf("\nLutfen oda tipini seciniz.\nStandart oda icin 'S', Deluxe oda icin 'D', Large Deluxe oda icin 'L' kodunu giriniz: ");
        scanf("%c",&oda_tipi);
        if (oda_tipi=='S')
        {
            printf("\n");
            for(i=0;i<=100;i++)
            {
                if (i%2==0)
                    continue;
                oda_sayisi[i]=i;
                printf("%d",oda_sayisi[i]);
                if (i!=99)
                    printf("---");
            }
            printf(" nolu odalar Standart odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=0;j<=100;j++)
                {
                    if (j%2==0 || j==0)
                        continue;
                    if (j%2==1)
                        oda_sayisi[j]=j;
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklanacak: ");
            scanf("%d",&misafir);
            misafir_degiskeni=misafir;
            if(misafir<=4)
                toplam_kisi=1;
            if(misafir>4)
            {
                while(misafir>4)
                {
                     misafir-=4;
                     misafir_sayac++;
                }
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                        while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || (digermisafir_odanumara[toplam_kisi]%2==0))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%2==0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                        toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=40*misafir_degiskeni;
        }
        else if (oda_tipi=='D')
        {

            printf("\n");
            for(i=0;i<102;i++)
            {
                if ((i%6!=0) && (i%2==0))
                {
                    if(i==0)
                        break;
                    oda_sayisi[i]=i;
                    printf("%d",oda_sayisi[i]);
                    if ((i+2)!=102)
                        printf("---");
                }
            }
            printf(" nolu odalar Deluxe odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=2;j<101;j++)
                {
                    if ((j%6!=0) && (j%2==0))
                    {
                        oda_sayisi[j]=j;
                    }
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklanacak: ");
            scanf("%d",&misafir);
            misafir_degiskeni=misafir;
            if(misafir<=4)
                toplam_kisi=1;
            if(misafir>4)
            {
                do
                {
                     misafir-=4;
                     misafir_sayac++;
                }
                while(misafir>4);
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                        while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || ((digermisafir_odanumara[toplam_kisi]%2!=0 || digermisafir_odanumara[toplam_kisi]%6==0)))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%2!=0 || digermisafir_odanumara[toplam_kisi]%6==0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                        toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=75*misafir_degiskeni;
        }
        else if (oda_tipi=='L')
        {
            printf("\n");
            for(i=0;i<=100;i++)
            {
                if (i%6==0)
                {
                    if (i==0)
                        continue;
                    oda_sayisi[i]=i;
                    printf("%d",oda_sayisi[i]);
                    if (i!=96)
                printf("---");
                }
            }
            printf(" nolu odalar Large Deluxe odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=0;j<100;j++)
                {
                    if (j%6==0)
                    {
                        oda_sayisi[j]=j;
                    }
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklayacak: ");
            scanf("%d",&misafir);
            if(misafir<=7)
                toplam_kisi=1;
            else if(misafir>7)
            {
                do
                {
                     misafir-=7;
                     misafir_sayac++;
                }
                while(misafir>7);
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                    while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || (digermisafir_odanumara[toplam_kisi]%6!=0))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%6!=0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                    toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=300*misafir_sayac;
        }
        break;
    }
    case 'Y':
    {
        mevsim_kontrol="Yaz";
        do
        {
            printf("\nYaz ayinin kacinci haftasinda konaklama yapilacagini giriniz: ");
            scanf("%d",&hafta);
            fflush(stdin);
            if(hafta<1 || hafta>12)
            {
                hafta_sayac++;
            }
            if(hafta_sayac==3)
            {
                printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                exit(0);
            }
        }
        while(hafta<1 || hafta>12);
        printf("\nLutfen oda tipini seciniz.\nStandart oda icin 'S', Deluxe oda icin 'D', Large Deluxe oda icin 'L' kodunu giriniz: ");
        scanf("%c",&oda_tipi);
        if (oda_tipi=='S')
        {
            printf("\n");
            for(i=0;i<=100;i++)
            {
                if (i%2==0)
                    continue;
                oda_sayisi[i]=i;
                printf("%d",oda_sayisi[i]);
                if (i!=99)
                    printf("---");
            }
            printf(" nolu odalar Standart odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=0;j<=100;j++)
                {
                    if (j%2==0 || j==0)
                        continue;
                    if (j%2==1)
                        oda_sayisi[j]=j;
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklanacak: ");
            scanf("%d",&misafir);
            misafir_degiskeni=misafir;
            if(misafir<=4)
                toplam_kisi=1;
            if(misafir>4)
            {
                while(misafir>4)
                {
                     misafir-=4;
                     misafir_sayac++;
                }
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                        while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || (digermisafir_odanumara[toplam_kisi]%2==0))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%2==0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                        toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=60*misafir_degiskeni;
        }
        else if (oda_tipi=='D')
        {
            printf("\n");
            for(i=0;i<102;i++)
            {
                if ((i%6!=0) && (i%2==0))
                {
                    if(i==0)
                        break;
                    oda_sayisi[i]=i;
                    printf("%d",oda_sayisi[i]);
                    if ((i+2)!=102)
                        printf("---");
                }
            }
            printf(" nolu odalar Deluxe odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=2;j<101;j++)
                {
                    if ((j%6!=0) && (j%2==0))
                    {
                        oda_sayisi[j]=j;
                    }
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklanacak: ");
            scanf("%d",&misafir);
            misafir_degiskeni=misafir;
            if(misafir<=4)
                toplam_kisi=1;
            if(misafir>4)
            {
                do
                {
                     misafir-=4;
                     misafir_sayac++;
                }
                while(misafir>4);
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                        while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || ((digermisafir_odanumara[toplam_kisi]%2!=0 || digermisafir_odanumara[toplam_kisi]%6==0)))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%2!=0 || digermisafir_odanumara[toplam_kisi]%6==0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                        toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=90*misafir_degiskeni;
        }
        else if (oda_tipi=='L')
        {
            printf("\n");
            for(i=0;i<=100;i++)
            {
                if (i%6==0)
                {
                    if (i==0)
                        continue;
                    oda_sayisi[i]=i;
                    printf("%d",oda_sayisi[i]);
                    if (i!=96)
                printf("---");
                }
            }
            printf(" nolu odalar Large Deluxe odalara dahildir.\n");
            do
            {
                printf("\nOda numarasini seciniz: ");
                scanf("%d",&oda_numara);
                for (j=0;j<100;j++)
                {
                    if (j%6==0)
                    {
                        oda_sayisi[j]=j;
                    }
                    if(oda_numara==oda_sayisi[j])
                    {
                        oda_numara_kontrol=j;
                        break;
                    }
                }
                if(oda_numara_kontrol==-1)
                    oda_numara_sayac++;
                if(oda_numara_sayac==3)
                {
                    printf("\n3 kere hatali giris yaptiniz ve program kapanmistir.\n");
                    exit(0);
                }
            }
            while(oda_numara_kontrol!=j);
            toplam_kisi=1;
            printf("\nRezerve edilen odadaki kisilerle birlikte toplam kac kisi konaklayacak: ");
            scanf("%d",&misafir);
            if(misafir<=7)
                toplam_kisi=1;
            else if(misafir>7)
            {
                do
                {
                     misafir-=7;
                     misafir_sayac++;
                }
                while(misafir>7);
                do
                {
                    printf("\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                    scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                    while((digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol) || (digermisafir_odanumara[toplam_kisi]%6!=0))
                        {
                            if(digermisafir_odanumara[toplam_kisi]==oda_numara_kontrol)
                            {
                                printf("Bu oda daha once rezerve edilmistir.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                            else if(digermisafir_odanumara[toplam_kisi]%6!=0)
                            {
                                printf("Secilen oda mevcut degil.\n\n%d. grup icin oda numarasi: ",toplam_kisi+1);
                                scanf("%d",&digermisafir_odanumara[toplam_kisi]);
                            }
                        }
                    toplam_kisi++;
                }
                while(toplam_kisi<misafir_sayac);
            }
            ucret=400*misafir_sayac;
        }
        break;
    }
    default:
    {
        system("CLS");
        return main();
    }
    break;
    }
    fflush(stdin);
    printf("\nRezervasyon ucreti seklini seciniz.\nOn odemeli islem icin 'O', Havale ile islem icin 'H', Standart odeme icin 'S' kodunu giriniz: ");
    scanf("%c",&ucret_sekli);
    switch(ucret_sekli)
    {
    case 'O':
    {
        on_odeme=(ucret*85)/100;
        printf("\nOn odemeli rezervasyon ucreti: %.2f",on_odeme);
        printf(" %c\n",(char)36);
        break;
    }
    case 'H':
    {
        if (oda_tipi=='L')
        {
            if (mevsim=='S')
            {
                ucret=250*misafir_sayac;
                printf("\nHavale ucreti: %.2f\n",ucret);
            }
            else if (mevsim=='B')
            {
                ucret=300*misafir_sayac;
                printf("\nHavale ucreti: %.2f\n",ucret);
            }
            else if (mevsim=='Y')
            {
                ucret=400*misafir_sayac;
                printf("\nHavale ucreti: %.2f\n",ucret);
            }
            break;
        }
        if (misafir_sayac<4)
            havale=ucret;
        else if (misafir_sayac==4 || misafir_sayac==5)
            havale=ucret-(ucret/misafir_sayac/2);
        else if (misafir_sayac>5)
            havale=ucret-(ucret/misafir_sayac/4);
        printf("\nHavale ucreti: %.2f",havale);
        printf(" %c\n",(char)36);
        break;
    }
    case 'S':
    {
        normal_odeme=ucret;
        printf("\nNormal (Standart) ucret: %.2f",normal_odeme);
        printf(" %c\n",(char)36);
        break;
    }
    default:
        break;
    }
    printf("\n%s Mevsiminin Doluluk Oranlari: \n",mevsim_kontrol);
    for(j=1;j<13;j++)
    {
        if(j==hafta)
        {
            printf("\n%2d. haftadaki doluluk orani: ",j);
            printf("%c",(char)37);
            printf("%d",toplam_kisi);
        }
        else
        {
            printf("\n%2d. haftadaki doluluk orani: ",j);
            printf("%c0",(char)37);
        }
    }
    printf("\n");
    fflush(stdin);
    printf("\nDevam etmek icin 'D', programdan cikmak icin 'C' - Seciminiz: ");
    scanf("%c",&tamam_ya_da_devam);
    switch(tamam_ya_da_devam)
    {
    case 'C':
        {
        printf("\nIsleminiz icin tesekkurler.\n");
        exit(0);
        }
        break;
    }
    }
    while(tamam_ya_da_devam=='D');
    return 0;
}
