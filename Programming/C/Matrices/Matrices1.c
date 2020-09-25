#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct mat{
	int col;
	int fil;
};

struct frac{
	int num;
	int den;	
};
/*
struct Frac multi(struct Frac var){
	struct Frac new;
	new.num = var.num * var.num;
	new.den = var.den * var.den;
	return new;
};

struct Frac sum(struct Frac var){
	struct Frac new;
	new.num = (var.num*var.den)+(var.den*var.num);
	new.den = var.den * var.den;
	return new;
	//Frac sum1 = new Frac((num*var.den)+(den*var.num), den * var.den);
};

/*struct Frac mcd(int num, int den){
	int var_num = num*;
	int var_den = den*;
	if(var_num == 0){
		return 1;
	}else{
		int mcd=1;
		while(var_den!=0){
			mcd = var_den;
			var_den = var_num%var_den; // modulo de la division
			var_num = mcd;
		}
		return mcd;
	}
}

void simpl(){
	int mcd = mcd();
	num = num/mcd;
	den = den/mcd;
}

struct Frac simplify(int den, int num){
  int mcd=2;
  if(den<0){
    num = num*(-1);
    den = den*(-1);
  }
  while(mcd<=fabs(num) && fabs(den)>=1){
    if ((num%mcd)==0 && (den%mcd)==0){
      num = num/mcd;
      den = den/mcd;
    }else{mcd++;}
  }
  struct Frac f; f.num = num; f.den = den;
  return f;
};*/

struct frac mcd(int n, int d){
  int i=2;
  if(d<0){
    n = n*(-1);
    d = d*(-1);
  }
  while(i<=fabs(n) && fabs(d)>=1){
    if ((n%i)==0 && (d%i)==0){
      n = (n/i);
      d = (d/i);
    }
    else{
        i++;
    }
  }
  struct frac a; 
  a.num = n; 
  a.den = d;
  return a;
}
struct frac suma(struct frac var, struct frac var1 ){
	struct frac n;
	n.num = (var.num * var1.den)+(var.den*var1.num);
	n.den = (var.den * var1.den);
	return n;
};
struct frac multi(struct frac var, struct frac var1 ){
	struct frac n;
	n.num = var.num *var1.num;
	n.den = var.den *var1.den;
	return n;
};
struct frac *mult( struct mat fil1, struct mat col1, struct frac *m1, struct mat fil2, struct mat col2, struct frac *m2, struct frac *m3 ){
    for(int i=0; i<fil1.fil; i++){
        for(int j=0; j<col2.col; j++){
            struct frac s; 
            s.num = 0;
            s.den = 1;
            for (int x=0; x<col1.col; x++){
                struct frac m;
                m = multi(*(m1+(col1.col*i)+x), *(m2+(col2.col*x)+j));
                s = suma(s, m);
      }*(m3+(col2.col*i)+j)=  mcd(s.num, s.den);;// = toString(s.num, s.den);
    }
  }
  return m3;
}
void toString (struct frac a, int imp){
  int num = a.num; 
	int den = a.den;
  int c1=1;
  int c2=1;

    if (c1<imp){
        for(int i=c1; i<imp; i++)
        printf(" ");
    }printf("%d/", a.num);

    if(c2<imp){
        for(int j=c2; j<imp; j++)
        printf(" ");
  }printf("%d", a.den);
}
int maxLength(struct mat matrix, struct frac *ptr){
  int num1, den1;
  int *arrLength;
  arrLength = malloc((matrix.fil*matrix.col)*sizeof(int));
  for(int x=0; x<(matrix.fil*matrix.col); x++){
      num1 = (*(ptr+x)).num;
      den1 = (*(ptr+x)).den;
      int c1 = 1; 
      int c2 = 1;
    if(c1>c2)
       *(arrLength+x) = c1;
    else
       *(arrLength+x) = c2;
  }
  int var_s = 1;
  for(int j=0; j<(matrix.fil*matrix.col); j++){
    if((*(arrLength+j))>var_s)
      var_s = *(arrLength+j);
  }
  return var_s;
}

void llenar(struct mat matrix, struct frac *ptr){
	char num[1025];
	for(int i = 0; i<(matrix.fil*matrix.col); i++){
			printf("Digite el num \n");
			fgets(num, 1025, stdin);
      		(*(ptr+i)).num = atoi(num);
			printf("Digite el den \n");
      		fgets(num, 1025, stdin);
      		(*(ptr+i)).den = atoi(num);
	}
}

/*void llenar1(struct mat fil2, struct mat col2, struct frac *ptr){
	char num[1025];
	for(int i = 0; i<(fil2.fil*col2.col); i++){
			printf("Digite el num \n");
			fgets(num, 1025, stdin);
      		(*(ptr+i)).num = atoi(num);
			printf("Digite el den \n");
      		fgets(num, 1025, stdin);
      		(*(ptr+i)).den = atoi(num);
	}
}*/

void mostrar(struct mat fil1, struct mat col1,struct frac *ptr, int imp){
	for(int i = 0; i<fil1.fil; i++){
		for (int j=0; j<col1.col; j++){
			printf(" ");
			toString(*(ptr+(col1.col*i)+j), imp);
			printf(" ");
            
		}printf(" \n");
	}
}
void mostrar1(struct mat fil2, struct mat col2, struct frac *ptr,int imp){
	for(int i = 0; i<fil2.fil; i++){
		for (int j=0; j<col2.col; j++){
			printf(" ");
			toString(*(ptr+(col2.col*i)+j), imp);
            
            printf(" ");
           
		}printf(" \n");
	}
}
void mostrar2(struct mat m ,struct frac *ptr,int imp){
	for(int i = 0; i<m.fil; i++){
		for (int j=0; j<m.col; j++){
			printf(" ");
			toString(*(ptr+(m.col*i)+j), imp);
            
            printf(" ");
           
		}printf(" \n");
	}
}


int main()
{	

  int imp;
	struct frac s;
	char num[1025]="";
	//1 mat
  struct mat mat1; 
	struct mat col1;
	//col1.col;
	struct mat fil1;
	//fil1.fil;
	//l2 mat
  struct mat mat2; 
	struct mat col2;
	//col2.col;
	struct mat fil2;
	//fil2.fil;
  int imp_resul;

	printf("How many rows in the first matrix?\n");
    fgets(num,1025,stdin);
	fil1.fil = atoi(num);
    printf("How many colums in the first matrix?\n");
    fgets(num,1025,stdin);
	col1.col = atoi(num);
	struct frac *m1;
   m1 = malloc((mat1.fil*mat1.col)* sizeof(struct frac));

    printf("How many rows in the second matrix?\n");
    fgets(num,1025,stdin);
	fil2.fil = atoi(num);
    printf("How many colums in the second matrix?\n");
    fgets(num,1025,stdin);
	col2.col = atoi(num);
	struct frac *m2;
  m2= malloc((mat2.fil*mat2.col)* sizeof(struct frac));

	if (col1.col==fil2.fil){
		llenar(mat1,m1);
    llenar(mat2,m2);
    
    printf("\n"); 
		printf(" MATRIX 1\n");
		mostrar(fil1,col1,m1,imp);
		printf("\n"); 
		printf(" X\n");
		printf("\n"); 
		printf(" MATRIX 2\n");
    printf("\n"); 
    printf(" =\n");
		mostrar1(fil2, col2, m2, imp);
    printf("RESULT MATRIX\n");
    struct mat fil3_col3;
    struct mat col3;
	  col3.col;
	  struct mat fil3;
	  fil3.fil;
    struct frac * m3;
    m3 = malloc((fil3.fil*col3.col)* sizeof(struct frac));
    struct frac *m3_resul;
    m3_resul = mult(fil1, col1, m1, fil2, col2, m2, m3);
    imp_resul = maxLength(fil3_col3, m3_resul);
    mostrar2(fil3_col3, m3, imp);
    printf("\n");
	}
	else{
		printf("The operation is impossible");
	}
	

	return 0;
}

