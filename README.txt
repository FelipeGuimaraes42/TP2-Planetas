----------------------------------------------------------------------------------
Salve o arquivo "felipe_guimaraes.zip" na área de trabalho;
Extraia a pasta "felipe_guimaraes";
No Terminal ou no CMD, abra o diretório com o comando:
	cd Desktop/felipe_guimaraes
Para voltar entre os diretórios, use o comando do Terminal/CMD:
	cd ../
Para compilar o código, abra mais um diretório:
	cd src
----------------------------------------------------------------------------------
*LINUX*
O compilador utilizado para Linux foi o gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0

Dentro da pasta src, pelo Terminal, dê o comando:
	make run

O código irá executar, apenas siga as instruções do programa.

Para rodar os testes, dê o comando: 
	make test

Após compilar o programa, dê o comando abaixo para apagar os arquivos temporários:
	make clean
----------------------------------------------------------------------------------
*WINDOWS*
O compilador utilizado para Windows foi o gcc (MinGW.org GCC-8.2.0-3) 8.2.0

Dentro da pasta src, pelo CMD, dê os comandos:
	g++ -std=c++17 main.cpp planeta.cpp mergesort.cpp radixsort.cpp -o tp2

O código irá executar, apenas siga as instruções do programa.
----------------------------------------------------------------------------------