#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int  main(int argc, char* argv[]){
    if(argc!=4){
        printf("Usage: ./resize n infile outfile");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if(n < 1 || n >100 ){
        return 2;
    }
    
    char* infile = argv[2];
    char* outfile = argv[3];
    
    FILE* inptr = fopen(infile,"r");
    if(inptr == NULL){
        printf("Could not open %s.\n",infile);
        return 3;
    }
    
    FILE* outptr = fopen(outfile,"w");
    if(outptr == NULL){
        fclose(inptr);
        fprintf(stderr,"Could not create %s.\n",outfile);
        return 4;
    }
    
    BITMAPFILEHEADER bfip,bfop;
    fread(&bfip, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    BITMAPINFOHEADER biip,biop;
    fread(&biip, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    if (bfip.bfType != 0x4d42 || bfip.bfOffBits != 54 || biip.biSize != 40 || 
        biip.biBitCount != 24 || biip.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    biop = biip;
    biop.biWidth = biip.biWidth * n;
    biop.biHeight = biip.biHeight * n;
    
    int paddingop =  (4 - (biop.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingip =  (4 - (biip.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    biop.biSizeImage = biop.biWidth * abs(biop.biHeight) * 3 + paddingop * abs(biop.biHeight);
    
    bfop = bfip;
    bfop.bfSize = biop.biSizeImage + bfop.bfOffBits;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bfop, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biop, sizeof(BITMAPINFOHEADER), 1, outptr);
    
     for (int i = 0, biHeight = abs(biip.biHeight); i < biHeight; i++)
    {
        
        for(int p = 0; p < n ; p++){
            
                // iterate over pixels in scanline
            for (int j = 0; j < biip.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                for(int k = 0; k < n ; k++){
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
                
                
            }
            
            fseek(inptr, paddingip, SEEK_CUR);
                
                for (int k = 0; k < paddingop; k++)
                {
                    fputc(0x00, outptr);
                }
                
            fseek(inptr, -(biip.biWidth*sizeof(RGBTRIPLE) + paddingip),SEEK_CUR);
        }
        fseek(inptr, (biip.biWidth*sizeof(RGBTRIPLE) + paddingip),SEEK_CUR);
    }
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
    
}