#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    string start;
    int option, original[4][4], matrizjogador[4][4] = {0}, i=0, j=0, aleatorio = rand()%10, numero = 1, aux = 0, guess, linha, coluna, linha2, coluna2, tentativas=12, vitoria;
    do{
        system("cls");
        cout << "-----------------------" << endl << endl;
        cout << "Seja muito bem-vindo(a) ao Jogo da Memória!"
        << endl << endl << "O jogo da memória é um clássico onde peças com imagens são dispostas viradas para baixo."
        << endl << "Os jogadores viram duas peças por vez, tentando encontrar pares idênticos."
        << endl << "Se acertam, ficam com o par; se erram, as peças são viradas novamente."
        << endl << "O vencedor é quem coleta mais pares." << endl << endl;
        cout << "-----------------------" << endl << endl;
        cout << "Digite 1 para começar e 2 para finalizar o jogo." << endl << endl;;
        cout << ">> "; cin >> option;
        switch(option){
            case 1:
                system("cls");
                // Criação da matriz do jogo original
                    for(i=0; i < 4; i++){
                        for(j=0;j < 4; j++){
                            original[i][j] = numero;
                            original[i][j + 1] = numero;
                            j++;
                            numero++;
                        }
                    }
                // Embaralhar essa matriz
                    for(i=0; i < 4; i++){
                        for(j=0;j < 4; j++){
                            int trocaI = rand() % 4;
                            int trocaJ = rand() % 4;
                            swap(original[i][j], original[trocaI][trocaJ]);
                        }
                    }

                tentativas=12;
                vitoria=1;
                do{
                    system("cls");
                    // GABARITO
                    //for(i=0; i < 4; i++){
                    //    for(j=0;j < 4; j++){
                    //        cout << original[i][j] << " ";
                    //    }
                    //    cout << endl;
                    //}

                    //cout << endl << endl;

                    for(i=0; i < 4; i++){
                        for(j=0;j < 4; j++){
                            if(matrizjogador[i][j] == 0){
                                cout << "X ";
                            } else {
                                cout << matrizjogador[i][j] << " ";
                            }
                        }
                        cout << endl;
                    }
                    cout << endl;
                    // PERGUNTAS
                    cout << "-----------------------" << endl << endl;
                    cout << "Restam apenas " << tentativas << " tentativas" << endl << endl;
                    cout << "-----------------------" << endl << endl;
                    cout << "Digite a linha que deseja: (0 a 3)" << endl;
                    cout << ">> "; cin >> linha;
                    cout << "Digite a coluna que deseja: (0 a 3)" << endl;
                    cout << ">> "; cin >> coluna; cout << endl;
                    cout << "Linha " << linha << " e " << "coluna " << coluna << endl;
                    cout << endl << endl;
                    cout << "-----------------------" << endl << endl;
                    if(linha > 3 || linha < 0 || coluna > 3 || coluna < 0){
                        cout << endl << endl;
                        cout << "Digite apenas números de 0 a 3, tente novamente." << endl;
                        cout << endl << endl;
                        cout << "-----------------------" << endl << endl;
                        cout << "Digite a linha que deseja: (0 a 3)" << endl;
                        cout << ">> "; cin >> linha;
                        cout << "Digite a coluna que deseja: (0 a 3)" << endl;
                        cout << ">> "; cin >> coluna;
                        cout << endl << endl;
                        cout << "-----------------------" << endl << endl;
                    }

                    for(i=0; i < 4; i++){
                        for(j=0;j < 4; j++){
                            if(matrizjogador[i][j] != 0){
                                cout << matrizjogador[i][j] << " ";
                            } else if(i == linha && j == coluna){
                                cout << original[i][j] << " ";
                            } else {
                                cout << "X ";
                            }
                        }
                        cout << endl;
                    }

                    cout << endl << endl;

                    cout << "-----------------------" << endl << endl;
                    cout << "Restam apenas " << tentativas << " tentativas" << endl << endl;
                    cout << "-----------------------" << endl << endl;
                    cout << "Agora tente achar o par" << endl;
                    cout << "Digite a linha que deseja: (0 a 3)" << endl;
                    cout << ">> "; cin >> linha2;
                    cout << "Digite a coluna que deseja: (0 a 3)" << endl;
                    cout << ">> "; cin >> coluna2; cout << endl;
                    cout << "Linha " << linha2 << " e " << "coluna " << coluna2 << endl;
                    cout << endl << endl;
                    cout << "-----------------------" << endl << endl;

                    if(linha2 > 3 || linha2 < 0 || coluna2 > 3 || coluna2 < 0){
                        cout << endl << endl;
                        cout << "Digite apenas números de 0 a 3, tente novamente." << endl;
                        cout << endl << endl;
                        cout << "-----------------------" << endl << endl;
                        cout << "Digite a linha que deseja: (0 a 3)" << endl;
                        cout << ">> "; cin >> linha2;
                        cout << "Digite a coluna que deseja: (0 a 3)" << endl;
                        cout << ">> "; cin >> coluna2;
                        cout << endl << endl;
                        cout << "-----------------------" << endl << endl;
                    }

                    for(i=0; i < 4; i++){
                        for(j=0;j < 4; j++){
                            if(matrizjogador[i][j] != 0){
                                cout << matrizjogador[i][j] << " ";
                            }
                            else if(i == linha && j == coluna){
                                cout << original[i][j] << " ";
                            }
                            else if(i == linha2 && j == coluna2){
                                cout << original[i][j] << " ";
                            } else {
                                cout << "X ";
                            }
                        }
                        cout << endl;
                    }

                    if(original[linha][coluna] == original[linha2][coluna2]){
                        matrizjogador[linha][coluna] = original[linha][coluna];
                        matrizjogador[linha2][coluna2] = original[linha2][coluna2];
                        cout << endl << endl;
                        cout << "-----------------------" << endl << endl;
                        cout << endl << endl;
                        cout << "Você acertou, parabéns!" << endl << endl;
                        tentativas++;
                    }

                    cout << endl << endl;
                    cout << "-----------------------" << endl << endl;
                    cout << "Digite 1 para uma nova tentativa" << endl;
                    cout << endl << endl;

                    cout << ">> "; cin >> option;

                    guess = 0;
                    for(i=0; i < 4; i++){
                        for(j=0;j < 4; j++){
                            if(matrizjogador[i][j] == original[i][j]){
                                guess += 1;
                                vitoria = 1;
                            }
                        }
                    }
                    if(tentativas < 1){
                        system("cls");
                        cout << "-----------------------" << endl << endl;
                        cout << "Você perdeu, tente novamente. (digite um número para voltar)" << endl << endl;
                        cout << "-----------------------" << endl << endl;
                        cout << ">> "; cin >> option;
                        guess = 16;
                    }

                    tentativas--;
                }while(guess != 16);
                if(vitoria == 1){
                    cout << "-----------------------" << endl << endl;
                    cout << "Parabéns você ganhou! (digite um número para voltar)" << endl << endl;
                    cout << "-----------------------" << endl << endl;
                    cout << ">> "; cin >> option;
                }
            case 2:
                // Acaba
                break;
            default:
                system("cls");
                cout << "-----------------------" << endl << endl;
                cout << "Apenas é válido o número 1 ou 2." << endl << "Digite qualquer coisa para voltar ao menu" << endl << endl;
                cout << ">> "; cin >> option;
                break;
        }
    }while(option != 2);
    return 0;
}
