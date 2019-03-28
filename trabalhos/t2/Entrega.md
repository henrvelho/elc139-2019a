ELC 139-2019 ANDREA CHARÃO
ALUNO: HENRIQUE VELHO
2019/01
PROGRAMAÇÃO PARALELA;

FOI UTILIZADO UM COMPUTADOR WINDOWS 10 COM BASH UBUNTU.
COM INTEL CORE I5 3337U 2 CORES

Questões Pthreads:
1- Explique como se encontram implementadas as 4 etapas de projeto: particionamento, comunicação, aglomeração, mapeamento (use trechos de código para ilustrar a explicação).

PARTICIONAMENTO:
	O particionamento eh responsavel por quando dividimos o processamento em partes menores para que seja possivel a paralelização, sendo que cada thread poderá processar um "pedaço" do problema.
	A parte do código responsável por isso e a função dotprod_worker(void *arg){},

	``` c

			void *dotprod_worker(void *arg){
			.....
			}

	```
COMUNICAÇÃO:
	É necessario a comunicação entre as threads para adicionar o resultado calculado na estrutura dotdata.c. Para liberar o acesso de uma variavel para somente uma thread é utilizado um flag mutex

	```
    pthread_mutex_lock (&mutexsum);
    dotdata.c += mysum;
    pthread_mutex_unlock (&mutexsum);
    ```

AGLOMERAÇÃO:
	A proposta de aglomeração é juntar as tarefas para diminuir os problemas na comunicação entre elas, no código abaixo, na função dotprod_worker, dependendo dos resultados das multiplicações sobre os vetores, é acrescido somas na variavel mysum.


2- Considerando o tempo (em microssegundos) mostrado na saída do programa, qual foi a aceleração (speedup) com o uso de threads?

	```
	henrvelho@Admin:~/Windows/Documents/GitHub/elc139-2019a/trabalhos/t2/pthreads_dotprod$ ./pthreads_dotprod 1 1000000 2000
	10000.000000
	1 thread(s), 7036090 usec
	henrvelho@Admin:~/Windows/Documents/GitHub/elc139-2019a/trabalhos/t2/pthreads_dotprod$ ./pthreads_dotprod 2 500000 2000
	10000.000000
	2 thread(s), 4475513 usec
	henrvelho@Admin:~/Windows/Documents/GitHub/elc139-2019a/trabalhos/t2/pthreads_dotprod$ ./pthreads_dotprod 4 250000 2000
	10000.000000
	4 thread(s), 3212582 usec
	```
	A taxa de aceleração de uso de 1 thread para 2 threads eh de 1.5721 de melhora. 



3- A aceleração se sustenta para outros tamanhos de vetores, números de threads e repetições? Para responder a essa questão, você terá que realizar diversas execuções, variando o tamanho do problema (tamanho dos vetores e número de repetições) e o número de threads (1, 2, 4, 8..., dependendo do número de núcleos). Cada caso deve ser executado várias vezes, para depois calcular-se um tempo de processamento médio para cada caso. Atenção aos fatores que podem interferir na confiabilidade da medição: uso compartilhado do computador, tempos muito pequenos, etc.

4- Elabore um gráfico/tabela de aceleração a partir dos dados obtidos no exercício anterior.
	Para realização dessa tabela foi utlizado 2 execuções no mesmo parametro e feito a média.

	Para MIL(1000) repetições:<br>

| Tam. Vetor | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 3501690         |
| 500.000          | 2            | 2317107         |
| 250.000          | 4            | 1630540         |
| 125.000          | 8            | 1632232         |
| 62.500           | 16           | 1621328         |

   <br>Para Para DUAS MIL(2000) repetições:<br>
   
| Tam. Vetor | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 7037472        |
| 500.000          | 2            | 4855846         |
| 250.000          | 4            | 3220299         |
| 125.000          | 8            | 3514569         |
| 62.500           | 16           | 3161884         |

   <br>Para CINCO MIL(5000) repetições:<br>
   
| Tam. Vetor | Núm. Threads |  Tempo Médio(usec) |
|:---------------:|:------------:|:------------------:|
| 1.000.000         | 1            | 17510459         |
| 500.000          | 2            | 11189053         |
| 250.000          | 4            | 8124235         |
| 125.000          | 8            | 8011778         |
| 62.500           | 16           | 7857310           |




5- Explique as diferenças entre pthreads_dotprod.c e pthreads_dotprod2.c. Com as linhas removidas, o programa está correto?

	Não, pois sem um mutex vai ocorrer de várias threads acessando a mesma estrutura concorrente e assim podendo ocasionar problemas de consistencia nos dados.