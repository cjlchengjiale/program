#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a;
int main(void)
{
	printf("����������Ҫ����ɼ�ѧ���ĸ���:");
	scanf("%d",&a);
	//printf("\n");
	float fourscore[a][4];
	long long xuehao[a];
	char name[a][10];
	for(int i=1;i<=a;i++){
		printf("��%d��ѧ��������:",i);
		scanf("%s",name[i-1]);
        printf("������%s��ѧ��:",name[i-1]);
        scanf("%I64d",&xuehao[i-1]);
        //printf("\n");
		printf("������%s�ĳɼ�:",name[i-1]);
                for(int k=0;k<1;k++){
            	for(int b=0;b<4;b++){
            		scanf("%f",&fourscore[i-1][b]);
			    }
			}
}
        float zongfen[a] = {0};
        float pingjunfen[a];
        float temp;
        //printf("%f",fourscore[0][0]);
        for(int i=0;i<a;i++){
        	zongfen[i]=0;
        		for(int d=0;d<4;d++){
        			zongfen[i]+=fourscore[i][d];
				}
			printf("%s���ܷ�Ϊ%.2f\n", name[i],zongfen[i]);
		}
		for(int e=0;e<a;e++){
				pingjunfen[e]=zongfen[e]/4.0;
				printf("%s��ƽ����Ϊ%.2f\n",name[e],pingjunfen[e]);
			}
			char name1[a][10];
			float zongfen1[a];
			float pingjunfen1[a];
			for(int f=0;f<a;f++){
				for(int g=0;g<a-f;g++){
					if(zongfen[g]>zongfen[g+1]){
						temp=zongfen[g];
						zongfen[g]=zongfen[g+1];
						zongfen[g+1]=temp;
					//	zongfen1[]=zongfen[g];
					//	pingjunfen1[f]=pingjunfen[g];
					//	name1[f][10]=name[g][10];
					}
				}
			}
			printf("��%d��ͬѧ����������\n",a);
			for(int h=0;h<a;h++){
				//zongfen1[h]=zongfen[h];
				printf("%f\n",zongfen[h]);
			}
			return 0;
}
