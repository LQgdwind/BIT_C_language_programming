void matrix_add(double matrix[3][3],double other[3][3])  
{  
    int i,j;  
    for(i=0;i<3;i++)  
    {  
        for(j=0;j<3;j++) matrix[i][j]+=other[i][j];  
    }  
}  
void matrix_subtract(double matrix[3][3],double other[3][3])  
{  
    int i,j;  
    for(i=0;i<3;i++)  
    {  
        for(j=0;j<3;j++) matrix[i][j]-=other[i][j];  
    }  
}  
void matrix_multiply(double matrix[3][3],double other[3][3])  
{  
    double cc[3][3];  
    int i,j;  
    for(i=0;i<3;i++)  
    {  
        for(j=0;j<3;j++) cc[i][j]=matrix[i][j];  
    }  
    for(i=0;i<3;i++)      
                {      
                    for(j=0;j<3;j++)      
                    {      
                        matrix[i][j]=cc[i][0]*other[0][j]+cc[i][1]*other[1][j]+cc[i][2]*other[2][j];      
                    }      
                }      
}  
void matrix_power(double matrix[3][3],int left_index)  
{  
    int i,j;      
    if(left_index==1||left_index==0){}      
    else if(left_index%2)      
    {         
        double dd[3][3],cc[3][3];      
        for(i=0;i<3;i++)      
        {      
            for(j=0;j<3;j++) dd[i][j]=matrix[i][j];      
        }      
        matrix_power(matrix,left_index-1);  
        for(i=0;i<3;i++)  
    {  
        for(j=0;j<3;j++) cc[i][j]=matrix[i][j];  
    }      
        for(i=0;i<3;i++)      
        {      
            for(j=0;j<3;j++)      
            matrix[i][j]=dd[i][0]*cc[0][j]+dd[i][1]*cc[1][j]+dd[i][2]*cc[2][j];      
        }      
    }      
    else      
    {  
    double cc[3][3];          
        for(i=0;i<3;i++)  
    {  
        for(j=0;j<3;j++) cc[i][j]=matrix[i][j];  
    }  
                for(i=0;i<3;i++)      
                {      
                    for(j=0;j<3;j++)      
                    {      
                        matrix[i][j]=cc[i][0]*cc[0][j]+cc[i][1]*cc[1][j]+cc[i][2]*cc[2][j];      
                    }      
                }      
                matrix_power(matrix,left_index/2);      
    }      
}  
void matrix_inverse(double matrix[3][3])  
{  
    int i,j;  
    double d[3][3];  
    double M=matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[0][1]*matrix[1][2]*matrix[2][0]+matrix[1][0]*matrix[2][1]*matrix[0][2]-matrix[0][0]*matrix[1][2]*matrix[2][1]-matrix[0][1]*matrix[1][0]*matrix[2][2]-matrix[0][2]*matrix[1][1]*matrix[2][0];      
        for(i=0;i<3;i++)      
        {      
            for(j=0;j<3;j++) d[i][j]=matrix[i][j];      
        }     
    matrix[0][0]=(d[1][1]*d[2][2]-d[2][1]*d[1][2])/M;      
    matrix[1][0]=(d[2][0]*d[1][2]-d[1][0]*d[2][2])/M;      
    matrix[2][0]=(d[1][0]*d[2][1]-d[2][0]*d[1][1])/M;      
    matrix[0][1]=(d[0][2]*d[2][1]-d[0][1]*d[2][2])/M;      
    matrix[1][1]=(d[0][0]*d[2][2]-d[0][2]*d[2][0])/M;      
    matrix[2][1]=(d[0][1]*d[2][0]-d[0][0]*d[2][1])/M;      
    matrix[0][2]=(d[0][1]*d[1][2]-d[1][1]*d[0][2])/M;      
    matrix[1][2]=(d[1][0]*d[0][2]-d[0][0]*d[1][2])/M;      
    matrix[2][2]=(d[0][0]*d[1][1]-d[1][0]*d[0][1])/M;      
}
