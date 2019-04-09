Programação Paralela

Aluno:Henrique Velho

Professora: Andrea Charão;

T3 Openmp

O presente trabalho foi criado, compilado e executado em um notebook Dell Inspiron Intel core I53337u

1- [Schedule Static] (https://github.com/henrvelho/elc139-2019a/blob/master/trabalhos/t3/ThreadStatic.cpp)

Neste caso como o proprio nome diz, o numero de iteracao será o mesmo, gerando uma saida uniforme;

2- [Schedule Dynamic] Com tratamento da exclusão mutua (https://github.com/henrvelho/elc139-2019a/blob/master/trabalhos/t3/ThreadDynamic.cpp)

3- [Schedule Guided] Com tratamento da exclusão mutua (https://github.com/henrvelho/elc139-2019a/blob/master/trabalhos/t3/ThreadGuided.cpp)

Neste caso o numero de iteraçoes irá variar, comecando por um numero grande e reduzindo ao final, como podemos ver na saida do programa(C>B>A)

4- [Schedule Runtime] (https://github.com/henrvelho/elc139-2019a/blob/master/trabalhos/t3/ThreadRuntime.cpp)

A decisao eh feita na execução do programa

5- [Schedule Auto] e sem tratamento da exclusão mutua (https://github.com/henrvelho/elc139-2019a/blob/master/trabalhos/t3/ThreadAuto.cpp)

Neste caso não foi feito a omp critical o qual libera o acesso a qualquer thread e a qualquer momento, e a saida é um resultado errado;

Referencias:

- Executando OpenMp (https://github.com/henrvelho/elc139-2019a/blob/master/trabalhos/t3/ThreadAuto.cpp)
- Introdução OpenMP (https://www.dcc.fc.up.pt/~fds/aulas/PPD/0708/intro_openmp-1x2.pdf)
- Diretivas OpenMp (https://docs.microsoft.com/pt-br/cpp/parallel/openmp/reference/openmp-directives?view=vs-2019)
