//Isadora Brust e Ana Carolina
//25/04/2023 - Primeiro Trabalho Baixo Nível
#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	int i, j, r;

	struct image_s imgFinal;

	r = read_ppm("lena.ppm", image);

	if (r == 0)
	{
		//cria nova imagem, zerando todos os pixeis, com o tamanho três vezes maior
		r = new_ppm(&imgFinal, image->width*3, image->height*3);

		//verifica se a imagem existe e não houve nenhuma problema na criação dela
		if(r != 0){
			printf("a imagem final nao foi criada");
			return 0;
		}
	
		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				//verifica se a cor red do pixel da imagem original está com valor de 0 a 74 inclusive
				if(image->pix[j * image->width + i].r <= 74){
					//como todos os pixeis da imagem já estão zerados, eu não preciso zerar o r
				}
				//verifica se a cor red do pixel da imagem original está com valor de 75 a 134 inclusive
				else if(image->pix[j * image->width + i].r <= 134){	
					//para mover para a próxima "linha" faz j*3 (o tamanho da largura da nova imagem) e mais 1 para próxima linha
					imgFinal.pix[(j * 3 + 1) * imgFinal.width + i * 3].r = 255;
				}
				//verifica se a cor red do pixel da imagem original está com valor de 135 a 179 inclusive
				else if(image->pix[j * image->width + i].r <= 179){
					imgFinal.pix[(j * 3 + 0) * imgFinal.width + i * 3].r = 255;
					imgFinal.pix[(j * 3 + 2) * imgFinal.width + i * 3].r = 255;
				}
				//se a cor red do pixel da imagem original está com valor de 180 a 255 inclusive
				else {
					imgFinal.pix[(j * 3 + 0) * imgFinal.width + i * 3].r = 255;
					imgFinal.pix[(j * 3 + 1) * imgFinal.width + i * 3].r = 255;
					imgFinal.pix[(j * 3 + 2) * imgFinal.width + i * 3].r = 255;
				}
				
				//verifica se a cor green do pixel da imagem original está com valor de 0 a 74 inclusive
				if(image->pix[j * image->width + i].g <= 74){
					//como todos os pixeis da imagem já estão zerados, eu não preciso zerar o g
				}
				//verifica se a cor green do pixel da imagem original está com valor de 75 a 134 inclusive
				else if(image->pix[j * image->width + i].g <= 134){	
					//para mover para a próxima coluna faz i*3 (que o tamanho da coluna da nova imagem) e mais 1 para pular pra proxima
					//coluna onde tem os valores de green
					imgFinal.pix[(j * 3 + 1) * imgFinal.width + (i * 3 + 1)].g = 255;
				}
				//verifica se a cor green do pixel da imagem original está com valor de 135 a 179 inclusive
				else if(image->pix[j * image->width + i].g <= 179){
					imgFinal.pix[(j * 3 + 0) * imgFinal.width + (i * 3 + 1)].g = 255;
					imgFinal.pix[(j * 3 + 2) * imgFinal.width + (i * 3 + 1)].g = 255;
				}
				//se a cor green do pixel da imagem original está com valor de 180 a 255 inclusive
				else {
					imgFinal.pix[(j * 3 + 0) * imgFinal.width + (i * 3 + 1)].g = 255;
					imgFinal.pix[(j * 3 + 1) * imgFinal.width + (i * 3 + 1)].g = 255;
					imgFinal.pix[(j * 3 + 2) * imgFinal.width + (i * 3 + 1)].g = 255;
				}
				
				//verifica se a cor blue do pixel da imagem original está com valor de 0 a 74 inclusive
				if(image->pix[j * image->width + i].b <= 74){
					//como todos os pixeis da imagem já estão zerados, eu não preciso zerar o b
				}
				//verifica se a cor blue do pixel da imagem original está com valor de 75 a 134 inclusive
				else if(image->pix[j * image->width + i].b <= 134){	
					imgFinal.pix[(j * 3 + 1) * imgFinal.width + (i * 3 + 2)].b = 255;
				}
				//verifica se a cor blue do pixel da imagem original está com valor de 135 a 179 inclusive
				else if(image->pix[j * image->width + i].b <= 179){
					imgFinal.pix[(j * 3 + 0) * imgFinal.width + (i * 3 + 2)].b = 255;
					imgFinal.pix[(j * 3 + 2) * imgFinal.width + (i * 3 + 2)].b = 255;
				}
				//se a cor blue do pixel da imagem original está com valor de 180 a 255 inclusive
				else {
					imgFinal.pix[(j * 3 + 0) * imgFinal.width + (i * 3 + 2)].b = 255;
					imgFinal.pix[(j * 3 + 1) * imgFinal.width + (i * 3 + 2)].b = 255;
					imgFinal.pix[(j * 3 + 2) * imgFinal.width + (i * 3 + 25)].b = 255;
				}
			}
		}

		write_ppm("lena_copy.ppm", &imgFinal);

		free_ppm(image);
		free_ppm(&imgFinal);
	}

	return 0;
}
