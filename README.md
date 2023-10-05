## Objetivo
Utilização da função fork() para criar um pipeline simples de comunicação
entre processos.
## Descrição
Você deverá criar um programa que simule um pipeline simples de
comunicação entre processos usando a função fork(). Um pipeline é uma técnica
de comunicação em que a saída de um processo serve como entrada para outro.
Neste caso, teremos dois processos envolvidos: um produtor e um consumidor.
O produtor gerará mensagens e o consumidor as lerá do pipeline.
## Requisitos
Crie um programa em C/C++ que utilize a função fork() para criar dois
processos: um produtor e um consumidor.
O processo produtor deve ser responsável por gerar mensagens (cadeias
de caracteres) e escrevê-las em um descritor de arquivo que será compartilhado
com o processo consumidor. Cada mensagem gerada pelo produtor deve ser
única e identificável, como "Mensagem 1", "Mensagem 2", e assim por diante.
Veja a Figura 1.
O processo consumidor deve ser responsável por ler as mensagens do
descritor de arquivo compartilhado e imprimi-las na saída padrão. Certifique-se
de que o processo consumidor imprima as mensagens na ordem em que foram
produzidas.
Use as funções pipe() ou pipe2(), da API do Linux, para criar o pipeline
entre os dois processos. O produtor deve escrever em uma extremidade
(pipe[1]) e o consumidor deve ler da outra extremidade (pipe[0]).
Garanta que os processos produtor e consumidor se comuniquem de
forma adequada, de modo que o consumidor espere até que haja alguma
mensagem disponível para leitura.

![Pipe](/.github/assets/pipe.png)

## Orientações
Utilize um loop no processo produtor para gerar várias mensagens.
Lembre-se de fechar os descritores de arquivo não utilizados em cada
processo para evitar vazamentos de recursos.
Considere utilizar a função strlen() para determinar o tamanho das
mensagens ao lê-las do pipeline no processo consumidor.
