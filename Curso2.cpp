#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib> 

using namespace std;

#define t 20

	struct cidades{
		int codigoCidade;
		string nome;
		char uf[2];
		int status;	
	};
		
	struct cursos{
		int codigoCurso;
		int valorAula;
		string descricao;	
		int status;
	};

	struct instrutores{
		int codigoInstrutor;
		int codigoCidade;
		string nome;
		string endereco;
		int status;
	};
	
	struct alunos{
		int codigoAluno;
		int codigoCidade;
		string nome;
		string endereco;
		int status;
	};
	
	struct turmas{
		int codigoTurma;
		int codigoCurso;
		int codigoInstrutor;
		int totalParticipantes;
		int maxParticipantes;
		int status;
	};
	
	struct matriculas{
		int codigoMatricula;
		int codigoAluno;
		int codigoTurma;
		int qntdAulas;
		int valorTotal;
		int status;
	};
	
	struct indTurma{
		int codigoTurma;
		int endTurma;
	};
	
	struct indCurso{
		int codigoCurso;
		int endTurma;
	};
	
	struct indMatricula{
		int codigoMatricula;
		int endMatricula;
	};
	
	struct indAluno{
		int codigoAluno;
		int endAluno;
	};
	
	struct indice{
		int codigo;
        int ender;
	};
	
	void indiceCidades(struct indice idxCidades[], int contCD) {
	    for (int i = 0; i < contCD; i++) {
	        cout << "\nCodigo do Indice " << (i + 1) << ": ";
	        cin >> idxCidades[i].codigo;
	        cout << "Endereco Fisico na Area de Dados: ";
	        cin >> idxCidades[i].ender;
	    }
	}
	
	void indiceCursos(struct indice idxCursos[], int contCS) {
	    for (int i = 0; i < contCS; i++) {
	        cout << "\nCodigo do Indice " << (i + 1) << ": ";
	        cin >> idxCursos[i].codigo;
	        cout << "Endereco Fisico na Area de Dados: ";
	        cin >> idxCursos[i].ender;
	    }
	}
	
	void indiceInstrutores(struct indice idxInstrutores[], int contIT){
		for (int i = 0; i < contIT; i++) {
	        cout << "\nCodigo do Indice " << (i + 1) << ": ";
	        cin >> idxInstrutores[i].codigo;
	        cout << "Endereco Fisico na Area de Dados: ";
	        cin >> idxInstrutores[i].ender;
	    }
	}
	
	void indiceTurmas(struct indice idxTurmas[], int contTR){
		for (int i = 0; i < contTR; i++) {
	        cout << "\nCodigo do Indice " << (i + 1) << ": ";
	        cin >> idxTurmas[i].codigo;
	        cout << "Endereco Fisico na Area de Dados: ";
	        cin >> idxTurmas[i].ender;
	    }
	}
	
	void indiceAlunos(struct indice idxAlunos[], int contAL){
		for (int i = 0; i < contAL; i++) {
	        cout << "\nCodigo do Indice " << (i + 1) << ": ";
	        cin >> idxAlunos[i].codigo;
	        cout << "Endereco Fisico na Area de Dados: ";
	        cin >> idxAlunos[i].ender;
	    }
	}
	
	void indiceMatriculas(struct indice idxMatriculas[], int contMT){
		for (int i = 0; i < contMT; i++) {
	        cout << "\nCodigo do Indice " << (i + 1) << ": ";
	        cin >> idxMatriculas[i].codigo;
	        cout << "Endereco Fisico na Area de Dados: ";
	        cin >> idxMatriculas[i].ender;
	    }
	}
	
	void leituraCidades(struct indice idx[], struct cidades cidades[], int &contCD, int cod) {
	    int i = 0, f = contCD - 1;
	    int m = (i + f) / 2;
	    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
	        if (cod > idx[m].codigo)
	            i = m + 1;
	        else
	            f = m - 1;
	    }
	    if(cod == idx[m].codigo){
	        cout << "\n Cidade já Cadastrada!!";
	        i = idx[m].ender;
	        return;
	    } else {
		    cidades[contCD].codigoCidade = cod;
		    cout << "\n============= CIDADE =============\n";
		    cout << "Cidade: ";
		    cin >> cidades[contCD].nome;
		    cout << "UF: ";
		    cin >> cidades[contCD].uf;
		    cidades[contCD].status = 0;
		    cout << "Status - " << cidades[contCD].status;
		    for (int j = contCD - 1; idx[j].codigo > cod; j--) {
		        idx[j + 1].codigo = idx[j].codigo;
		        idx[j + 1].ender = idx[j].ender;
		    }
		    idx[i].codigo = cod;
		    idx[i].ender = contCD;  
		    contCD++;
		    cout << "\n\nInclusão realizada com sucesso";
		    cout << "\n==================================\n";
		}
	}

	void leituraCursos (struct indice idx[], struct cursos cursos[], int &contCS, int cod){
		int i = 0, f = contCS - 1;
	    int m = (i + f) / 2;
	    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
	        if (cod > idx[m].codigo)
	            i = m + 1;
	        else
	            f = m - 1;
	    }
	    if(cod == idx[m].codigo){
	        cout << "\n Curso já Cadastrado!!";
	        i = idx[m].ender;
	        return;
	    } else {
			cursos[contCS].codigoCurso = cod;
			cout << "Descrição do Curso: ";
			cin >> cursos[contCS].descricao;
			cout << "Valor da Aula: R$";
			cin >> cursos[contCS].valorAula;
			cursos[contCS].status = 0;
			cout << "Status - " << cursos[contCS].status;
			for (int j = contCS - 1; idx[j].codigo > cod; j--) {
			    idx[j + 1].codigo = idx[j].codigo;
			    idx[j + 1].ender = idx[j].ender;
			}
			idx[i].codigo = cod;
			idx[i].ender = contCS; 
			contCS++;
			cout << "\n\nInclusão realizada com sucesso";
			cout << "\n==================================\n";
		}
	}
		
	void leituraInstrutores(struct indice idx[], struct instrutores instrutores[], struct cidades cidades[], int &contIT, int contCD, int cod){
	    int i = 0, f = contIT - 1;
	    int m = (i + f) / 2;
	    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
	        if (cod > idx[m].codigo)
	            i = m + 1;
	        else
	            f = m - 1;
	    }
	    if(cod == idx[m].codigo){
	        cout << "\n Instrutor já Cadastrado!!";
	        i = idx[m].ender;
	        return;
	    } else {
	        instrutores[contIT].codigoInstrutor = cod;
	        cout << "Código da Cidade do Instrutor: ";
	        cin >> instrutores[contIT].codigoCidade;
	        for (int j = 0; j < contCD; j++) { 
	            if (instrutores[contIT].codigoCidade == cidades[j].codigoCidade) {
	                if (cidades[j].status == 0) {
	                    cout << "\nCidade - " << cidades[j].nome << " / " << cidades[j].uf;
	                    cout << "\n\nNome: ";
	                    cin >> instrutores[contIT].nome;
	                    cout << "Endereço: ";
	                    cin >> instrutores[contIT].endereco;
	                    instrutores[contIT].status = 0;
	                    cout << "Status - " << instrutores[contIT].status;
	                    for (int x = contIT - 1; x >= i && idx[x].codigo > cod; x--) {
	                        idx[x + 1].codigo = idx[x].codigo;
	                        idx[x + 1].ender = idx[x].ender;
	                    }
	                    idx[i].codigo = cod;
	                    idx[i].ender = contIT;
	                    contIT++;
	                    cout << "\n\nInclusão realizada com sucesso";
	                    cout << "\n==================================\n";
	                }
	                return; 
	            }
	        }
	        cout << "\n\n Cidade não existe!!";
			cout << "\n===========================\n"; 
		}
	}

	
	void leituraAlunos(struct indice idx[], struct alunos alunos[], struct cidades cidades[], int &contAL, int &contCD, int cod){
		int i = 0, f = contAL - 1;
	    int m = (i + f) / 2;
	    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
	        if (cod > idx[m].codigo)
	            i = m + 1;
	        else
	            f = m - 1;
	    }
	    if(cod == idx[m].codigo){
	        cout << "\n Aluno já Cadastrado!!";
	        i = idx[m].ender;
	        return;
	    } else {
			alunos[contAL].codigoAluno = cod;
	        cout << "Código da Cidade do Aluno: ";
	        cin >> alunos[contAL].codigoCidade;
	        for (int j = 0; j < contCD; j++) {
	            if (alunos[contAL].codigoCidade == cidades[j].codigoCidade){
	                if (cidades[j].status == 0) {
	                    cout << "\nCidade - " << cidades[j].nome << " / " << cidades[j].uf;
	                    cout << "\n\nNome: ";
	                    cin >> alunos[contAL].nome;
	                    cout << "Endereço: ";
	                    cin >> alunos[contAL].endereco;
	                    alunos[contAL].status = 0;
	                    cout << "Status - " << alunos[contAL].status;
	                    for (int x = contAL - 1; x >= i && idx[x].codigo > cod; x--) {
	                        idx[x + 1].codigo = idx[x].codigo;
	                        idx[x + 1].ender = idx[x].ender;
	                    }
	                    idx[i].codigo = cod;
	                    idx[i].ender = contAL;
	                    contAL++;
	                    cout << "\n\nInclusão realizada com Sucesso";
	                    cout << "\n==================================\n";
	                }
	                return; 
	            }
	        }
	        cout << "\n\n Cidade não encontrada!!";
			cout << "\n===========================\n";
	    }
	}
	
	void leituraTurmas(struct indice idx[], struct turmas turmas[], struct instrutores instrutores[], struct cursos cursos[], struct cidades cidades[], int &contTR, int &contIT, int &contCS, int &contCD, int cod){
	    int i = 0, f = contTR - 1;
	    int m = (i + f) / 2;
	    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
	        if (cod > idx[m].codigo)
	            i = m + 1;
	        else
	            f = m - 1;
	    }
	    if(cod == idx[m].codigo){
	        cout << "\n Turma já Cadastrada!!";
	        i = idx[m].ender;
	        return;
	    } else {
	        turmas[contTR].codigoTurma = cod;
	        cout << "\nCódigo do Curso: ";
	        cin >> turmas[contTR].codigoCurso;
	        for (int j = 0; j < contCS; j++) {
	            if ((turmas[contTR].codigoCurso == cursos[j].codigoCurso) && cursos[j].status == 0) {
	                cout << "\nCurso - " << cursos[j].descricao;
	                cout << "\nValor da Aula - R$ " << cursos[j].valorAula;
	                cout << "\n\nCódigo do Instrutor: ";
	                cin >> turmas[contTR].codigoInstrutor;
	                for (int h = 0; h < contIT; h++) {
	                    if ((turmas[contTR].codigoInstrutor == instrutores[h].codigoInstrutor) && instrutores[h].status == 0) {
	                        cout << "\nInstrutor - " << instrutores[h].nome;
	                        for (int l = 0; l < contCD; l++) {
	                            if (instrutores[h].codigoCidade == cidades[l].codigoCidade) {
	                                cout << "\nCidade - " << cidades[l].nome << " / " << cidades[l].uf;
	                            }
	                        }
	                        cout << "\n\nTotal máximo de Participantes: ";
	                        cin >> turmas[contTR].maxParticipantes;
	                        turmas[contTR].totalParticipantes = 0;
	                        turmas[contTR].status = 0;
	                        cout << "\nStatus - " << turmas[contTR].status;
	
	                        for (int x = contTR - 1; x >= i && idx[x].codigo > cod; x--) {
	                            idx[x + 1].codigo = idx[x].codigo;
	                            idx[x + 1].ender = idx[x].ender;
	                        }
	                        idx[i].codigo = cod;
	                        idx[i].ender = contTR;
	                        contTR++;
	                        cout << "\n\nInclusão realizada com sucesso";
	                        cout << "\n==================================\n";
	                        return;
	                    }
	                }
	                cout << "\nInstrutor não encontrado!!\n";
					cout << "\n===========================\n"; 
	                return; 
	            }
	        }
	        cout << "\nCurso não encontrado!!\n";
	        cout << "\n===========================\n";
		}
	}
	
	void leituraMatriculas (struct indice idx[], struct matriculas matriculas[], struct cidades cidades[], struct alunos alunos[], struct turmas turmas[], struct cursos cursos[], struct instrutores instrutores[], int &contMT, int &contCD, int &contAL, int &contTR, int &contCS, int &contIT, int cod){
		int i = 0, f = contMT - 1;
	    int m = (i + f) / 2;
	    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
	        if (cod > idx[m].codigo)
	            i = m + 1;
	        else
	            f = m - 1;
	    }
	    if (cod == idx[m].codigo) {
	        cout << "\n Matrícula já Cadastrada!!";
	        i = idx[m].ender;
	    } else {
	        matriculas[contMT].codigoMatricula = cod;
	        cout << "\n\nQuantidade de Aulas: ";
	        cin >> matriculas[contMT].qntdAulas;
	        cout << "\nCódigo do Aluno: ";
	        cin >> matriculas[contMT].codigoAluno;
	        int j;
	        for (j = 0; j < contAL; j++) {
	            if ((matriculas[contMT].codigoAluno == alunos[j].codigoAluno) && alunos[j].status == 0) {
	                cout << "\nAluno - " << alunos[j].nome;
	                cout << "\nEndereço: " << alunos[j].endereco;
	                for (int Q = 0; Q < contCD; Q++) {
	                    if (alunos[j].codigoCidade == cidades[Q].codigoCidade) {
	                        cout << "\nCidade - " << cidades[Q].nome << " / " << cidades[Q].uf;
	                    }
	                }
	                cout << "\n\nCódigo da Turma: ";
	                cin >> matriculas[contMT].codigoTurma;
	                int h;
	                for (h = 0; h < contTR; h++) {
	                    if ((matriculas[contMT].codigoTurma == turmas[h].codigoTurma) && turmas[h].status == 0) {
	                        if (turmas[h].totalParticipantes < turmas[h].maxParticipantes) {
	                            turmas[h].totalParticipantes++;
	                            cout << "\nTurma - " << turmas[h].codigoTurma;
	                            cout << "\nQuantidade máxima de Participantes: " << turmas[h].maxParticipantes;
	                            for (int o = 0; o < contCS; o++) {
	                                if (turmas[h].codigoCurso == cursos[o].codigoCurso) {
	                                    cout << "\nCurso - " << cursos[o].descricao;
	                                    cout << "\nValor da Aula - R$" << cursos[o].valorAula;
	                                    matriculas[contMT].valorTotal = matriculas[contMT].qntdAulas * cursos[o].valorAula;
	                                }
	                            }
	                            for (int y = 0; y < contIT; y++) {
	                                if (turmas[h].codigoInstrutor == instrutores[y].codigoInstrutor) {
	                                    cout << "\nInstrutor - " << instrutores[y].nome;
	                                    cout << "\nEndereço: " << instrutores[y].endereco;
	                                    for (int l = 0; l < contCD; l++) {
	                                        if (instrutores[y].codigoCidade == cidades[l].codigoCidade) {
	                                            cout << "\nCidade - " << cidades[l].nome << " / " << cidades[l].uf;
	                                        }
	                                    }
	                                }
	                            }
	                            cout << "\nValor Total - R$" << matriculas[contMT].valorTotal;
	                            matriculas[contMT].status = 0;
	                            cout << "Status - " << matriculas[contMT].status;
	                            for (int x = contMT - 1; x >= i && idx[x].codigo > cod; x--) {
	                                idx[x + 1].codigo = idx[x].codigo;
	                                idx[x + 1].ender = idx[x].ender;
	                            }
	                            idx[i].codigo = cod;
	                            idx[i].ender = contMT;
	                            contMT++;
	                            cout << "\n\nInclusão realizada com sucesso";
	                            return;
	                        } else {
	                            cout << "\nTurma já está CHEIA!!\n";
	                            return;
	                        }
	                    }
	                }
	                cout << "\nTurma não encontrada\n";
	                return;
	            }
	        }
	        cout << "\nAluno não encontrado\n";
	    }
	}


	void exibirCursos(struct indice idx[], struct cursos cursos[], int contCS){
		int exi;
		cout << "\n=======================================";
		cout << "\n  (Status: 0 - Ativo / 1 - Desativado)  \n";
		cout << "\nExibir codigos Ativados ou Desativado: ";
		cin >> exi;
		if(exi == 0){
			for (int k = 0; k < contCS; k++) {
		        if (cursos[k].status == 0) {
		            cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
		            cout << "\nID - " << cursos[k].codigoCurso;
		            cout << "\nDescrição: " << cursos[k].descricao;
		            cout << "\nValor da Aula - R$ " << cursos[k].valorAula;
		            cout << "\nStatus: " << cursos[k].status << " - Ativo";
		            cout << "\n==============================";
		        }
			}    
		}
		if(exi == 1){
			for (int k = 0; k < contCS; k++) {
		        if (cursos[k].status == 1) {
		            cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
		            cout << "\nID - " << cursos[k].codigoCurso;
		            cout << "\nDescrição: " << cursos[k].descricao;
		            cout << "\nValor da Aula - R$ " << cursos[k].valorAula;
		            cout << "\nStatus: " << cursos[k].status << " - Desativado";
		            cout << "\n==================================\n";
		        }
		    }
		}
	}
	
	void exibirCidades(struct indice idx[], struct cidades cidades[], int contCD) {
		int exi;
		cout << "\n=======================================";
		cout << "\n  (Status: 0 - Ativo / 1 - Desativado)  \n";
		cout << "\nExibir codigos Ativados ou Desativado: ";
		cin >> exi;
		if(exi == 0){
			for (int k = 0; k < contCD; k++) {
		        if (cidades[k].status == 0) {
		            cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
		            cout << "\nID - " << cidades[k].codigoCidade; 
		            cout << "\nCidade: " << cidades[k].nome << "/" << cidades[k].uf;
		            cout << "\nStatus: " << cidades[k].status << " - Ativo";
		            cout << "\n==================================\n";
		        }
			}
		}
		if(exi == 1){
			for (int k = 0; k < contCD; k++) {
		        if (cidades[k].status == 1) {
		            cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
		            cout << "\nID - " << cidades[k].codigoCidade; 
		            cout << "\nCidade: " << cidades[k].nome << "/" << cidades[k].uf;
		            cout << "\nStatus: " << cidades[k].status << " - Desativado";
		            cout << "\n==================================\n";
		        }
		    }
		}
	}
	
	void exibirInstrutores(struct indice idxInstrutores[], struct instrutores instrutores[], struct cidades cidades[], int contIT, int contCD){
	    int exi;
	    cout << "\n=======================================";
	    cout << "\n  (Status: 0 - Ativo / 1 - Desativado)  \n";
	    cout << "\nExibir codigos Ativados ou Desativado: ";
	    cin >> exi;
	    if(exi == 0) {
	        for (int k = 0; k < contIT; k++) {
	            if (instrutores[k].status == 0) {  
	                cout << "\nIndice - " << idxInstrutores[k].codigo << " Endereço - " << idxInstrutores[k].ender;
	                cout << "\nID - " << instrutores[k].codigoInstrutor;
	                for (int j = 0; j < contCD; j++) { 
	                    if ((instrutores[k].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
	                cout << "\nNome: " << instrutores[k].nome;
	                cout << "\nEndereço: " << instrutores[k].endereco;
	                cout << "\n==============================\n";
	            }
	        }
	    } else if(exi == 1) {
	        for (int k = 0; k < contIT; k++) {
	            if (instrutores[k].status == 1) {  
	                cout << "\nIndice - " << idxInstrutores[k].codigo << " Endereço - " << idxInstrutores[k].ender;
	                cout << "\nID - " << instrutores[k].codigoInstrutor;
	                for (int j = 0; j < contCD; j++) { 
	                    if ((instrutores[k].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
	                cout << "\nNome: " << instrutores[k].nome;
	                cout << "\nEndereço: " << instrutores[k].endereco;
	                cout << "\n==============================\n";
	            }
	        }
	    }
	}
	
	void reorganizacao (struct indice idx[], struct alunos alunos[], int &contAL){
	    struct alunos novoAlunos[contAL];
		int j = - 1;
	    for (int k=0; k < contAL; k++){
	        int i = idx[k].ender;
	        if (alunos[i].status == 0){
	            j++;
	            novoAlunos[j] = alunos[i];
	            idx[j].codigo = novoAlunos[j].codigoAluno;
	            idx[j].ender = j;
	        }
	    }
	    contAL = j + 1;
	    for (int k = 0; k < contAL; k++){
	    	int i = idx[k].ender;
	    	alunos[k] = novoAlunos[i];
		}
	}
	
	void exibirAlunos(struct indice idx[], struct alunos alunos[], struct cidades cidades[], int contAL, int contCD){
	    int exi;
	    cout << "\n=======================================";
	    cout << "\n  (Status: 0 - Ativo / 1 - Desativado)  \n";
	    cout << "\nExibir codigos Ativados ou Desativado: ";
	    cin >> exi;
	    if(exi == 0) {
	        for (int k = 0; k < contAL; k++) {
	            if (alunos[k].status == 0) {  
		            cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
		            cout << "\nID - " << alunos[k].codigoAluno;
	                for (int j = 0; j < contCD; j++) { 
	                    if ((alunos[k].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
	                cout << "\nNome: " << alunos[k].nome;
	                cout << "\nEndereço: " << alunos[k].endereco;
	                cout << "\n==============================";
	            }
	        }
	    } else if(exi == 1) {
	        for (int k = 0; k < contAL; k++) {
	            if (alunos[k].status == 1) {  
	                cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
		            cout << "\nID - " << alunos[k].codigoAluno;
	                for (int j = 0; j < contCD; j++) { 
	                    if ((alunos[k].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
	                cout << "\nNome: " << alunos[k].nome;
	                cout << "\nEndereço: " << alunos[k].endereco;
	                cout << "\n==============================";
	            }
	        }
	    }
	    reorganizacao (idx, alunos, contAL);
	}
	
	void exibirTurmas(struct indice idx[], struct turmas turmas[], struct instrutores instrutores[], struct cursos cursos[], struct cidades cidades[], int contTR, int contIT, int contCS, int contCD){
	    int exi;
	    cout << "\n=======================================";
	    cout << "\n  (Status: 0 - Ativo / 1 - Desativado)  \n";
	    cout << "\nExibir codigos Ativados ou Desativado: ";
	    cin >> exi;
	    if(exi == 0) {
	        for (int k = 0; k < contTR; k++) {
	            if (turmas[k].status == 0) {  
	                cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
	                cout << "\nID - " << turmas[k].codigoTurma;
	                for (int c = 0; c < contCS; c++) { 
	                    if ((turmas[k].codigoCurso == cursos[c].codigoCurso) && cursos[c].status == 0) {
	                        cout << "\nCurso - " << cursos[c].descricao;
							cout << "\nValor R$" << cursos[c].valorAula; 
	                    }
	                }
	                for (int l = 0; l < contIT; l++) { 
	                    if ((turmas[k].codigoInstrutor == instrutores[l].codigoInstrutor) && instrutores[l].status == 0) {
	                        cout << "\nInstrutor - " << instrutores[l].nome;
							cout << "\nEndeço: " << instrutores[l].endereco; 
	                    }
	                }
	                for (int j = 0; j < contCD; j++) { 
	                    if ((instrutores[k].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
	                cout << "\nQuantidade máxima de Participantes: " << turmas[k].maxParticipantes;
	                cout << "\nTotal de Participantes - " << turmas[k].totalParticipantes;
	                if (turmas[k].totalParticipantes == turmas[k].maxParticipantes){
	                	cout << "\n\n Turma Completa!" ;
					}else if(turmas[k].totalParticipantes < turmas[k].maxParticipantes){
						cout << "\n\n Total de Participantes incluidos - " << turmas[k].totalParticipantes;
					} 
	                cout << "\nStatus: " << turmas[k].status << " - Ativo";
	                cout << "\n==============================\n";
	            }
	        }
	    } else if(exi == 1) {
	        for (int k = 0; k < contTR; k++) {
	            if (turmas[k].status == 1) {  
	                cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
	                cout << "\nID - " << turmas[k].codigoTurma;
	                for (int c = 0; c < contCS; c++) { 
	                    if ((turmas[k].codigoCurso == cursos[c].codigoCurso) && cursos[c].status == 0) {
	                        cout << "\nCurso - " << cursos[c].descricao;
							cout << "\nValor R$" << cursos[c].valorAula; 
	                    }
	                }
	                for (int l = 0; l < contIT; l++) { 
	                    if ((turmas[k].codigoInstrutor == instrutores[l].codigoInstrutor) && instrutores[l].status == 0) {
	                        cout << "\nInstrutor - " << instrutores[l].nome;
							cout << "\nEndeço: " << instrutores[l].endereco; 
	                    }
	                }
	                for (int j = 0; j < contCD; j++) { 
	                    if ((instrutores[k].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
	                cout << "\nQuantidade máxima de Participantes: " << turmas[k].maxParticipantes;
	                cout << "\nTotal de Participantes - " << turmas[k].totalParticipantes;
	                if (turmas[k].totalParticipantes == turmas[k].maxParticipantes){
	                	cout << "\n\n Turma Completa!" ;
					}else if(turmas[k].totalParticipantes < turmas[k].maxParticipantes){
						cout << "\n\n Total de Participantes incluidos - " << turmas[k].totalParticipantes;
					}
	                cout << "\nStatus: " << turmas[k].status << " - Desativado";
	                cout << "\n==============================\n";
	            }
	        }
	    }
	}
	
	void exibirMatriculas (struct indice idx[], struct matriculas matriculas[], struct cidades cidades[], struct alunos alunos[], struct turmas turmas[], struct cursos cursos[], struct instrutores instrutores[], int contMT, int contCD, int contAL, int contTR, int contCS, int contIT){
	    int exi;
	    cout << "\n=======================================";
	    cout << "\n  (Status: 0 - Ativo / 1 - Desativado)  \n";
	    cout << "\nExibir codigos Ativados ou Desativado: ";
	    cin >> exi;
	    if (exi == 0) {
	        for (int k = 0; k < contMT; k++) {
	            if (matriculas[k].status == 0) {
	                cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
	                cout << "\nID - " << matriculas[k].codigoMatricula;
	                for (int a = 0; a < contAL; a++) {
	                    if (matriculas[k].codigoAluno == alunos[a].codigoAluno) {
	                        cout << "\nAluno - " << alunos[a].nome;
	                        cout << "\nEndereço: " << alunos[a].endereco;
	                        for (int Q = 0; Q < contCD; Q++) {
	                            if (alunos[a].codigoCidade == cidades[Q].codigoCidade) {
	                                cout << "\nCidade - " << cidades[Q].nome << " / " << cidades[Q].uf;
	                            }
	                        }
	                    }
	                }
	                for (int p = 0; p < contTR; p++) {
	                    if (matriculas[k].codigoTurma == turmas[p].codigoTurma) {
	                        for (int c = 0; c < contCS; c++) {
	                            if (turmas[p].codigoCurso == cursos[c].codigoCurso) {
	                                cout << "\nCurso - " << cursos[c].descricao;
	                                cout << "\nValor da Aula - R$" << cursos[c].valorAula;
	                            }
	                        }
	                        for (int y = 0; y < contIT; y++) {
	                            if (turmas[p].codigoInstrutor == instrutores[y].codigoInstrutor) {
	                                cout << "\nInstrutor - " << instrutores[y].nome;
	                                cout << "\nEndereço: " << instrutores[y].endereco;
	                                for (int l = 0; l < contCD; l++) {
	                                    if (instrutores[y].codigoCidade == cidades[l].codigoCidade) {
	                                        cout << "\nCidade - " << cidades[l].nome << " / " << cidades[l].uf;
	                                    }
	                                }
	                            }
	                        }
	                    }
	                }
	                cout << "\nValor Total - R$" << matriculas[k].valorTotal;
	                cout << "\nStatus: " << matriculas[k].status << " - Ativo";
	                cout << "\n==============================\n";
	            }
	        }
	    } else if(exi == 1) {
	        for (int k = 0; k < contMT; k++) {
	            if (matriculas[k].status == 0) {
	                cout << "\nIndice - " << idx[k].codigo << " Endereço - " << idx[k].ender;
	                cout << "\nID - " << matriculas[k].codigoMatricula;
	                for (int a = 0; a < contAL; a++) {
	                    if (matriculas[k].codigoAluno == alunos[a].codigoAluno) {
	                        cout << "\nAluno - " << alunos[a].nome;
	                        cout << "\nEndereço: " << alunos[a].endereco;
	                        for (int Q = 0; Q < contCD; Q++) {
	                            if (alunos[a].codigoCidade == cidades[Q].codigoCidade) {
	                                cout << "\nCidade - " << cidades[Q].nome << " / " << cidades[Q].uf;
	                            }
	                        }
	                    }
	                }
	                for (int p = 0; p < contTR; p++) {
	                    if (matriculas[k].codigoTurma == turmas[p].codigoTurma) {
	                        for (int c = 0; c < contCS; c++) {
	                            if (turmas[p].codigoCurso == cursos[c].codigoCurso) {
	                                cout << "\nCurso - " << cursos[c].descricao;
	                                cout << "\nValor da Aula - R$" << cursos[c].valorAula;
	                            }
	                        }
	                        for (int y = 0; y < contIT; y++) {
	                            if (turmas[p].codigoInstrutor == instrutores[y].codigoInstrutor) {
	                                cout << "\nInstrutor - " << instrutores[y].nome;
	                                cout << "\nEndereço: " << instrutores[y].endereco;
	                                for (int l = 0; l < contCD; l++) {
	                                    if (instrutores[y].codigoCidade == cidades[l].codigoCidade) {
	                                        cout << "\nCidade - " << cidades[l].nome << " / " << cidades[l].uf;
	                                    }
	                                }
	                            }
	                        }
	                    }
	                }
	                cout << "\nValor Total - R$" << matriculas[k].valorTotal;
	                cout << "\nStatus: " << matriculas[k].status << " - Desativado";
	                cout << "\n==============================\n";
	            }
	        }
	    }
	}
	
	void buscarMatriculas(struct indice idx[], struct matriculas matriculas[], struct cidades cidades[], struct alunos alunos[], struct turmas turmas[], struct cursos cursos[], struct instrutores instrutores[], int contMT, int contCD, int contAL, int contTR, int contCS, int contIT, int cod){
		int i = 0, f = contMT - 1; 
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) { 
	            cout << "\n==================================";
	            cout << "\n     Aluno encontrado";	            
	            cout << "\nIndice - " << idx[m].codigo << " Endereço - " << idx[m].ender;
		        cout << "\nID - " << matriculas[m].codigoMatricula;
	            for (int c = 0; c < contCS; c++) { 
	                if ((matriculas[m].codigoAluno == alunos[c].codigoAluno) && cursos[c].status == 0) {
	                	cout << "\nAluno - " << alunos[c].nome;
			            cout << "\nEndereço: " << alunos[c].endereco;
			            for (int Q = 0; Q < contCD; Q++) {
			                if (alunos[c].codigoCidade == cidades[Q].codigoCidade) {
			                    cout << "\nCidade - " << cidades[Q].nome << " / " << cidades[Q].uf;
			                }
			            }
	                }
	            }
	            for (int p = 0; p < contTR; p++){
		            if(matriculas[m].codigoTurma == turmas[p].codigoTurma){
			            for (int c = 0; c < contCS; c++){
			                if ((turmas[p].codigoCurso == cursos[c].codigoCurso) && cursos[c].status == 0) {
			                    cout << "\nCurso - " << cursos[c].descricao;
	                            cout << "\nValor da Aula - R$" << cursos[c].valorAula;
			                }
			            }
			        }
				    for (int y = 0; y < contIT; y++){
		                if (turmas[p].codigoInstrutor == instrutores[p].codigoInstrutor) {
		                    cout << "\nInstrutor - " << instrutores[y].nome;
		                    cout << "\nEndereço: " << instrutores[y].endereco;
		                    for (int l = 0; l < contCD; l++) {
		                        if (instrutores[y].codigoCidade == cidades[l].codigoCidade) {
		                            cout << "\nCidade - " << cidades[l].nome << " / " << cidades[l].uf;
		                            }
		                        }
		                    }
		                }
					}
	            cout << "\nValor Total - R$" << matriculas[m].valorTotal;
	            if(alunos[m].status == 0){
	            	cout << "\nStatus: " << alunos[m].status << " - Ativo";
	            	cout << "\n==============================\n";
	            	return;
				}
				if(alunos[m].status == 1){
	            	cout << "\nStatus: " << alunos[m].status << " - Desativado";
	            	cout << "\n==============================\n";
	            	return;
				}
	        }
	        if (cod > idx[m].codigo)  
	            i = m + 1;
	        else  
	            f = m - 1;
	    }
	    cout << "\n\n Aluno não Encontrado\n";
	    cout << "\n==============================\n";
	}
	
	void buscarTurmas(struct indice idx[], struct turmas turmas[], struct instrutores instrutores[], struct cursos cursos[], struct cidades cidades[], int &contTR, int &contIT, int &contCS, int &contCD, int cod){
		int i = 0, f = contIT - 1; 
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) { 
	            cout << "\n==================================";
	            cout << "\n     Turma encontrada";	            
	            cout << "\nIndice - " << idx[m].codigo << " Endereço - " << idx[m].ender;
	            cout << "\nID - " << turmas[m].codigoTurma;
	            for (int c = 0; c < contCS; c++) { 
	                if ((turmas[m].codigoCurso == cursos[c].codigoCurso) && cursos[c].status == 0) {
	                    cout << "\nCurso - " << cursos[c].descricao;
						cout << "\nValor R$" << cursos[c].valorAula; 
	                }
	            }
	            for (int l = 0; l < contIT; l++) { 
	                if ((turmas[m].codigoInstrutor == instrutores[l].codigoInstrutor) && instrutores[l].status == 0) {
	                    cout << "\nInstrutor - " << instrutores[l].nome;
						cout << "\nEndeço: " << instrutores[l].endereco; 
	                }
	            }
	            for (int j = 0; j < contCD; j++) { 
	                if ((instrutores[m].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                    cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                }
	            }
	                cout << "\nQuantidade máxima de Participantes: " << turmas[m].maxParticipantes;
	            if(instrutores[m].status == 0){
	            	cout << "\nStatus: " << turmas[m].status << " - Ativo";
	            	cout << "\n==============================\n";
	            	return;
				}
				if(instrutores[m].status == 1){
	            	cout << "\nStatus: " << turmas[m].status << " - Desativado";
	            	cout << "\n==============================\n";
	            	return;
				}
	        }
	        if (cod > idx[m].codigo)  
	            i = m + 1;
	        else  
	            f = m - 1;
	    }
	    cout << "\n\n Turma não Encontrada\n";
	    cout << "\n==============================\n";
	}
	
	void buscarAlunos(struct indice idx[], struct alunos alunos[], struct cidades cidades[], int contAL, int contCD, int cod){
		int i = 0, f = contAL - 1; 
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) { 
	            cout << "\n==================================";
	            cout << "\n     Aluno encontrado";	            
	            cout << "\nIndice - " << idx[m].codigo << " Endereço - " << idx[m].ender;
		        cout << "\nID - " << alunos[m].codigoAluno;
	            for (int j = 0; j < contCD; j++) { 
	                    if ((alunos[m].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
				cout << "\nNome: " << alunos[m].nome;
	            cout << "\nEndereço: " << alunos[m].endereco;
	            if(alunos[m].status == 0){
	            	cout << "\nStatus: " << alunos[m].status << " - Ativo";
	            	cout << "\n==============================\n";
	            	return;
				}
				if(alunos[m].status == 1){
	            	cout << "\nStatus: " << alunos[m].status << " - Desativado";
	            	cout << "\n==============================\n";
	            	return;
				}
	        }
	        if (cod > idx[m].codigo)  
	            i = m + 1;
	        else  
	            f = m - 1;
	    }
	    cout << "\n\n Aluno não Encontrado\n";
	    cout << "\n==============================\n";
	}

	void buscarInstrutores(struct indice idxInstrutores[], struct instrutores instrutores[], struct cidades cidades[], int contIT, int contCD, int cod){
		int i = 0, f = contIT - 1; 
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idxInstrutores[m].codigo) { 
	            cout << "\n==================================";
	            cout << "\n     Instrutor encontrado";	            
	            cout << "\nIndice - " << idxInstrutores[m].codigo << " Endereço - " << idxInstrutores[m].ender;
	            cout << "\nID - " << instrutores[m].codigoInstrutor;
	            for (int j = 0; j < contCD; j++) { 
	                    if ((instrutores[m].codigoCidade == cidades[j].codigoCidade) && cidades[j].status == 0) {
	                        cout << "\nCidade - " << cidades[j].nome << "/" << cidades[j].uf;
	                    }
	                }
				cout << "\nNome: " << instrutores[m].nome;
	            cout << "\nEndereço: " << instrutores[m].endereco;
	            if(instrutores[m].status == 0){
	            	cout << "\nStatus: " << instrutores[m].status << " - Ativo";
	            	cout << "\n==============================\n";
	            	return;
				}
				if(instrutores[m].status == 1){
	            	cout << "\nStatus: " << instrutores[m].status << " - Desativado";
	            	cout << "\n==============================\n";
	            	return;
				}
	        }
	        if (cod > idxInstrutores[m].codigo)  
	            i = m + 1;
	        else  
	            f = m - 1;
	    }
	    cout << "\n\n Instrutor não Encontrado\n";
	}
	
	void buscarCursos(struct indice idx[], struct cursos cursos[], int &contCS, int cod) {
	    int i = 0, f = contCS - 1; 
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) { 
	            cout << "\n==================================";
	            cout << "\n     Curso encontrado";
	            cout << "\nIndice - " << idx[m].codigo << " Endereço - " << idx[m].ender;
	            cout << "\nID - " << cursos[m].codigoCurso;
	            cout << "\nDescrição: " << cursos[m].descricao;
	            cout << "\nValor da Aula - R$ " << cursos[m].valorAula;
	            if(cursos[m].status == 0){
	            	cout << "\nStatus: " << cursos[m].status << " - Ativo";
	            	cout << "\n==============================\n";
	            	return;
				}
				if(cursos[m].status == 1){
	            	cout << "\nStatus: " << cursos[m].status << " - Desativado";
	            	cout << "\n==============================\n";
	            	return;
				}
	        }
	        if (cod > idx[m].codigo)  
	            i = m + 1;
	        else  
	            f = m - 1;
	    }
	    cout << "\n\n Curso não Encontrado\n";
	    cout << "\n==============================\n";
	}
	
	void buscarCidades(struct indice idx[], struct cidades cidades[], int &contCD, int cod) {
	    int i = 0, f = contCD - 1; 
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) { 
	            cout << "\n==================================";
	            cout << "\n     Cidade encontrada";
	            cout << "\nIndice - " << idx[m].codigo << " Endereço - " << idx[m].ender;
	            cout << "\nID - " << cidades[m].codigoCidade;
	            cout << "\nCidade - " << cidades[m].nome << "/" << cidades[m].uf;
	            if(cidades[m].status == 0){
	            	cout << "\nStatus: " << cidades[m].status << " - Ativo";
	            	cout << "\n==============================\n";
	            	return;
				}
				if(cidades[m].status == 1){
	            	cout << "\nStatus: " << cidades[m].status << " - Desativado";
	            	cout << "\n==============================\n";
	            	return;
				}
	        }
	        if (cod > idx[m].codigo)  
	            i = m + 1;
	        else  
	            f = m - 1;
	    }
	    cout << "\n\n Cidade não Encontrada\n";
	    cout << "\n==============================\n";
	}
	
	void excluirCidades(struct indice idx[], struct cidades cidades[], int &contCD, int cod) {
	    int i = 0, f = contCD - 1;
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) {  
	            if (cidades[m].status == 0) { 
	                cidades[m].status = 1;  
	                cout << "\nCidade excluída com sucesso!\n";
	                cout << "\n==============================\n";
	            } else {
	                cout << "\nCidade já está excluída.\n";
	                cout << "\n==============================\n";
	            }
	            return; 
	        }
	        if (cod > idx[m].codigo) { 
	            i = m + 1;
	        } else {
	            f = m - 1;
	        }
	    }
	    cout << "\nCidade não cadastrada.\n";
	    cout << "\n==============================\n";
	}
	
	void excluirCursos(struct indice idx[], struct cursos cursos[], int &contCS, int cod) {
	    int i = 0, f = contCS - 1;
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) {  
	            if (cursos[m].status == 0) { 
	                cursos[m].status = 1;  
	                cout << "\nCurso excluído com sucesso!\n";
	                cout << "\n==============================\n";
	            } else {
	                cout << "\nCurso já está excluído.\n";
	                cout << "\n==============================\n";
	            }
	            return; 
	        }
	        if (cod > idx[m].codigo) { 
	            i = m + 1;
	        } else {
	            f = m - 1;
	        }
	    }
	    cout << "\nCidade não cadastrada.\n";
	    cout << "\n==============================\n";
	}
	
	void excluirInstrutores(struct indice idx[], struct instrutores instrutores[], struct turmas turmas[], struct matriculas matriculas[], int &contTR, int &contMT, int &contIT, int cod) {
	    int i = 0, f = contIT - 1;
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        for (int p = 0; p < contTR; p++) {
	            if (turmas[p].codigoInstrutor == instrutores[m].codigoInstrutor) {
	                cout << "\n==================================================================\n";
					cout << "\n\nInstrutor não pode ser Excluído / Está cadastrado em uma Turma!\n";
	                cout << "\n\n==================================================================\n";
	                return;
	            }
			}
	        if (cod == idx[m].codigo) {
	            if (instrutores[m].status == 0) {
	                instrutores[m].status = 1;
	                cout << "\nInstrutor excluído com sucesso!\n";
	                cout << "\n==============================\n";
	            } else {
	                cout << "\nInstrutor já está excluído.\n";
	                cout << "\n==============================\n";
	            }
	            return;
	        }
	        if (cod > idx[m].codigo) {
	            i = m + 1;
	        } else {
	            f = m - 1;
	        }
	    }
	    cout << "\nInstrutor não cadastrado.\n";
	    cout << "\n==============================\n";
	}
	
	void excluirAlunos(struct indice idx[], struct alunos alunos[], struct matriculas matriculas[], int &contAL, int &contMT, int cod) {
	    int i = 0, f = contAL - 1;
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        for (int j = 0; j < contMT; j++) {
	            if (alunos[m].codigoAluno == matriculas[j].codigoAluno) {
	            	cout << "\n==================================================================\n";
	                cout << "\n\nAluno não pode ser excluído / Está cadastrado em uma Turma!\n";
	                cout << "\n\n==================================================================\n";
	                return;
	            }
	        }
	        if (cod == idx[m].codigo) {
	            if (alunos[m].status == 0) {
	                alunos[m].status = 1;
	                cout << "\nAluno excluído com sucesso!\n";
	                cout << "\n===============================\n";
	            } else {
	                cout << "\nAluno já está excluído.\n";
	                cout << "\n===============================\n";
	            }
	            return;
	        }
	        if (cod > idx[m].codigo) {
	            i = m + 1;
	        } else {
	            f = m - 1;
	        }
	    }
	    cout << "\nAluno não cadastrado.\n";
	    cout << "\n===============================\n";
	}
	
	void excluirTurmas(struct indice idx[], struct turmas turmas[], int &contTR, int cod){
		 int i = 0, f = contTR - 1;
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) {  
	            if (turmas[m].status == 0) { 
	                turmas[m].status = 1;  
	                cout << "\nTurmas excluída com sucesso!\n";
	                cout << "\n==============================";
	            } else {
	                cout << "\nTurma já está excluída.\n";
	                cout << "\n==============================";
	            }
	            return; 
	        }
	        if (cod > idx[m].codigo) { 
	            i = m + 1;
	        } else {
	            f = m - 1;
	        }
	    }
	    cout << "\nTurma não cadastrada.\n";
	    cout << "\n==============================\n";
	}
	
	void excluirMatriculas(struct indice idx[], struct matriculas matriculas[], int &contMT, int cod){
		int i = 0, f = contMT - 1;
	    int m;
	    while (i <= f) {
	        m = (i + f) / 2;
	        if (cod == idx[m].codigo) {  
	            if (matriculas[m].status == 0) { 
	                matriculas[m].status = 1;  
	                cout << "\nMatrícula excluída com sucesso!\n";
	                cout << "\n==============================";
	            } else {
	                cout << "\nMatrícula já está excluída.\n";
	                cout << "\n==============================";
	            }
	            return; 
	        }
	        if (cod > idx[m].codigo) { 
	            i = m + 1;
	        } else {
	            f = m - 1;
	        }
	    }
	    cout << "\nMatrícula não cadastrada.\n";
	    cout << "\n==============================\n";
	}
	
	void finalizarMenu(){
	    cout << "\n";
	    cout << "===========================================\n";
	    cout << "                FINALIZADO                 \n";
	    cout << "===========================================\n";
	    cout << "+-----------------------------------------+\n";
	    cout << "  ¦ Obrigado por utilizar nosso sistema! ¦ \n";
	    cout << "+-----------------------------------------+\n";
	    cout << "===========================================\n";
	    cout << "\n";
	}
	
 	void menu (struct indice idxCidades[], struct indice idxCursos[], struct indice idxInstrutores[], 
		struct indice idxAlunos[], struct indice idxTurmas[], struct indice idxMatriculas[], 
		struct cidades cidades[], struct cursos cursos[], struct instrutores instrutores[], 
		struct alunos alunos[], struct turmas turmas[], struct matriculas matriculas[], 
		int contCD, int contCS, int contIT, int contAL, int contTR, int contMT){
		int tab;
		cout << "\n====================== MENU ======================    ";
		cout << "\n  1 - Cidade   /  2 - Cursos   /  3 - Instrutores     ";
		cout << "\n  4 - Alunos   /  5 - Turmas   /  6 - Matrículas      ";
		cout << "\n                 0 - Finalizar                        ";
		cout << "\n==================================================\n  ";
		cin >> tab;
		system("CLS");
		
		if (tab == 1) {
			int incluir;
		    int cod = -1;
		
		    while (cod != 0) {
		        cout << "\n========= CIDADE =========  ";
		        cout << "\n      1 - Adicionar         ";
		        cout << "\n      2 - Exibir            ";
		        cout << "\n      3 - Buscar            ";
		        cout << "\n      4 - Excluir           ";
		        cout << "\n      0 - Menu              ";
		        cout << "\n==========================\n";
		        cin >> incluir;
		        if (incluir == 0){
		        	menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				}
		        switch (incluir) {
		            case 1:
		            	cout << "\nInforme o Codigo a ser Incluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
							leituraCidades(idxCidades, cidades, contCD, cod);
							system("CLS");
						}
		                break;
		            
		            case 2:
		            	exibirCidades(idxCidades, cidades, contCD);
		            
		            	break;
		            	
		            case 3:
		            	cout << "\nInforme o Codigo a ser Buscado (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
		            		buscarCidades(idxCidades, cidades, contCD, cod);
		            	
						}
		            	break;
		            	
		            case 4:
		            	cout << "\nInforme o Codigo a ser Excluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
		            		excluirCidades(idxCidades, cidades, contCD, cod);
		            	
						}
		            	break;
		            	
		            default:
		                cout << "Opção inválida, tente novamente.\n";
		        }
		    }
		    menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
		}
		
		if (tab == 2) {
		    int incluir;
		    int cod = -1;
		
		    while (cod != 0) {
		        cout << "\n========= CURSOS =========  ";
		        cout << "\n      1 - Adicionar         ";
		        cout << "\n      2 - Exibir            ";
		        cout << "\n      3 - Buscar            ";
		        cout << "\n      4 - Excluir           ";
		        cout << "\n      0 - Menu              ";
		        cout << "\n==========================\n";
		        cin >> incluir;
		        if (incluir == 0){
		        	menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				}
		        switch (incluir) {
		            case 1:
		            	cout << "\nInforme o Codigo a ser Incluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
							leituraCursos(idxCursos, cursos, contCS, cod);
							system("CLS");
						}
		                break;
		            
		            case 2:
		              	exibirCursos(idxCursos, cursos, contCS);
		            	break;
		            
		            case 3:
		            	cout << "\nInforme o Codigo a ser Buscado (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
		            		buscarCursos(idxCursos, cursos, contCS, cod);
		            
						}
		            	break;
		            	
		            case 4:
		            	cout << "\nInforme o Codigo a ser Excluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
		            		excluirCursos(idxCursos, cursos, contCS, cod);
						}
		            	break;
		            	
		            default:
		                cout << "Opção inválida, tente novamente.\n";
		        }
		    }
		    menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
		}
		
		if (tab == 3) {
		    int incluir;
		    int cod = -1;
		
		    while (cod != 0) {
		        cout << "\n========= INSTRUTORES =========  ";
		        cout << "\n         1 - Adicionar           ";
		        cout << "\n         2 - Exibir              ";
		        cout << "\n         3 - Buscar              ";
		        cout << "\n         4 - Excluir             ";
		        cout << "\n         0 - Menu                ";
		        cout << "\n===============================\n";
		        cin >> incluir;
		        if (incluir == 0){
		        	menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				}
		        switch (incluir) {
		            case 1:
		            	cout << "\nInforme o Codigo a ser Incluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0){
				           menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
							leituraInstrutores(idxInstrutores, instrutores, cidades, contIT, contCD, cod);
							system("CLS");
						}
		                break;
		            
		            case 2:
		            	exibirInstrutores(idxInstrutores, instrutores, cidades, contIT, contCD);
		            	break;
		            	
		            case 3:
		            	cout << "\nInforme o Codigo a ser Buscado (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
		            		buscarInstrutores(idxInstrutores, instrutores, cidades, contIT, contCD, cod);
						}
		            	break;
		            	
		            case 4:
		            	cout << "\nInforme o Codigo a ser Excluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
		            		excluirInstrutores(idxInstrutores, instrutores, turmas, matriculas, contTR, contMT, contIT, cod);
						}
		            	break;
		            default:
		                cout << "Opção inválida, tente novamente.\n";
		        }
		    }
		    menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
		}
		
		if (tab == 4) {
		    int incluir;
		    int cod = -1;
		
		    while (cod != 0) {
		        cout << "\n========= ALUNOS =========  ";
		        cout << "\n      1 - Adicionar         ";
		        cout << "\n      2 - Exibir            ";
		        cout << "\n      3 - Buscar            ";
		        cout << "\n      4 - Excluir           ";
		        cout << "\n      0 - Menu              ";
		        cout << "\n==========================\n";
		        cin >> incluir;
		        if (incluir == 0){
		        	menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				}
		        switch (incluir) {
		            case 1:
		            	cout << "\nInforme o Codigo a ser Incluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
							leituraAlunos(idxAlunos, alunos, cidades, contAL, contCD, cod);
							system("CLS");
						}
		                break;
		            
		            case 2:
		            	exibirAlunos(idxAlunos, alunos, cidades, contAL, contCD);
		            	break;
		            
		            case 3:
		            	cout << "\nInforme o Codigo a ser Buscado (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
		            		buscarAlunos(idxAlunos, alunos, cidades, contAL, contCD, cod);
						}
		            	break;
		            	
		            case 4:
		            	cout << "\nInforme o Codigo a ser Excluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
		            		excluirAlunos(idxAlunos, alunos, matriculas, contMT, contAL, cod);
						}
		            	break;
		            default:
		                cout << "Opção inválida, tente novamente.\n";
		        }
		    }
		    menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
		}
		
		if (tab == 5) {
		    int incluir;
		    int cod = -1;
		
		    while (cod != 0) {
		        cout << "\n========= TURMAS =========  ";
		        cout << "\n      1 - Adicionar         ";
		        cout << "\n      2 - Exibir            ";
		        cout << "\n      3 - Buscar            ";
		        cout << "\n      4 - Excluir           ";
		        cout << "\n      0 - Menu              ";
		        cout << "\n==========================\n";
		        cin >> incluir;
		        if (incluir == 0){
		        	menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				}
		        switch (incluir) {
		            case 1:
		            	cout << "\nInforme o Codigo a ser Incluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				           menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
							leituraTurmas(idxTurmas, turmas, instrutores, cursos, cidades, contTR, contIT, contCS, contCD, cod);
							system("CLS");
						}
		                break;
		            
		            case 2:
		            	exibirTurmas(idxTurmas, turmas, instrutores, cursos, cidades, contTR, contIT, contCS, contCD);
		            	break;
		            	
		            case 3:
		            	cout << "\nInforme o Codigo a ser Buscado (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
		            		buscarTurmas(idxTurmas, turmas, instrutores, cursos, cidades, contTR, contIT, contCS, contCD, cod);
						}
		            	break;
		            	
		            case 4:
		            	cout << "\nInforme o Codigo a ser Excluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
		            		excluirTurmas(idxTurmas, turmas, contTR, cod);
						}
		            	break;
		            default:
		                cout << "Opção inválida, tente novamente.\n";
		        }
		    }
		    menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
		}
		
		if (tab == 6) {
		    int incluir;
		    int cod = -1;
		
		    while (cod != 0) {
		        cout << "\n========= MATRÍCULAS =========  ";
		        cout << "\n        1 - Adicionar           ";
		        cout << "\n        2 - Exibir              ";
		        cout << "\n        3 - Buscar              ";
		        cout << "\n        4 - Excluir             ";
		        cout << "\n        0 - Menu                ";
		        cout << "\n==============================\n";
		        cin >> incluir;
		        if (incluir == 0){
		        	menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				}
		        switch (incluir) {
		            case 1:
		            	cout << "\nInforme o Codigo a ser Incluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				          menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
				        }else{
							leituraMatriculas(idxMatriculas, matriculas, cidades, alunos, turmas, cursos, instrutores, contMT, contCD, contAL, contTR, contCS, contIT, cod);
							system("CLS");
						}
		                break;
		            
		            case 2:
		            	exibirMatriculas(idxMatriculas, matriculas, cidades, alunos, turmas, cursos, instrutores, contMT, contCD, contAL, contTR, contCS, contIT);
		            	break;
		            
		            case 3:
		            	cout << "\nInforme o Codigo a ser Buscado (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);; 
				        }else{
		            		buscarMatriculas(idxMatriculas, matriculas, cidades, alunos, turmas, cursos, instrutores, contMT, contCD, contAL, contTR, contCS, contIT, cod);
						}
		            	break;
		            	
		            case 4:
		            	cout << "\nInforme o Codigo a ser Excluido (0 para Encerrar): ";
				        cin >> cod;
				        if (cod == 0) {
				            menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
				        }else{
		            		excluirMatriculas(idxMatriculas, matriculas, contMT, cod);
						}
		            	break; 
		            default:
		                cout << "Opção inválida, tente novamente.\n";
		        }
		    }
		    menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT); 
		}
		
		if(tab == 0){
			finalizarMenu();
		}
	}
	
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	cidades cidades [t];
	cursos cursos [t];
	instrutores instrutores[t];
	alunos alunos[t];
	turmas turmas[t];
	matriculas matriculas[t];
	indice idxCidades[t];
	indice idxCursos[t];
	indice idxInstrutores[t];
	indice idxAlunos[t];
	indice idxTurmas[t];
	indice idxMatriculas[t];
	
	int contCD = 0;
	int contCS = 0;
	int contIT = 0;
	int contAL = 0;
	int contTR = 0;
	int contMT = 0;
		
	menu(idxCidades, idxCursos, idxInstrutores, idxAlunos, idxTurmas, idxMatriculas, cidades, cursos, instrutores, alunos, turmas, matriculas, contCD, contCS, contIT, contAL, contTR, contMT);
	
	getch();
}
