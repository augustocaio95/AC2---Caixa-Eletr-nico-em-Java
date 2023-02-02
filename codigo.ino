/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */
package com.mycompany.ac2;

import java.util.Scanner;

/**
 *
 * @author Caio Augusto Carvalho dos Santos 
 * RA : 224120 
 * Turma: AS002TSN1
 */
public class AC2 {

    public static void main(String[] args) {
        String cpfc = "12345678900", senhac = "01020304", cpf, senha;
        boolean cpfcontrole = false, logincontrole = false;
        double saldo = 1000;
        int opcao;
        Scanner ler = new Scanner(System.in);

        System.out.println("Bem-vindo!");
        System.out.println(" ");
        System.out.println("Por favor digite seu CPF: ");
        cpf = ler.nextLine();

        if (cpfc.equals(cpf)) {
            System.out.println("Acesso liberado!");
            System.out.print("\n");
            cpfcontrole = true;
        } else {
            System.out.println("CPF Inválido, acesso negado");
        }

        if (cpfcontrole) { // O código continua apenas com o CPF correto e pede a senha
            for (int i = 0; i < 3; i++) {
                System.out.println("Digite sua senha: ");
                senha = ler.nextLine();
                if (senhac.equals(senha)) {
                    System.out.println("\n");
                    System.out.println("Acesso liberado!");
                    System.out.println("\n");
                    logincontrole = true;
                    break;
                } else {
                    if (i == 2) {  // A conta é bloqueada pois o usuário já errou 3x a senha
                        System.out.println("Conta bloqueada, excedeu o numero de tentativas");
                    } else {
                        System.out.println("Senha inválida, digite novamente");
                    }
                }
            }
        }

        if (logincontrole) { // Após vefiricação da senha com sucesso, exibe o menu
            do {
                System.out.print("MENU PRINCIPAL");
                System.out.println("\n");
                System.out.println("1 - Saldo");
                System.out.println("2 - Depósito");
                System.out.println("3 - Saque");
                System.out.println("0 - Sair");
                System.out.print("\n");

                opcao = ler.nextInt();

                switch (opcao) {
                    case 1:
                        System.out.print("Saldo atual da sua conta: R$" + saldo);
                        System.out.println("\n");
                        break;
                    case 2:
                        System.out.print("Insira o valor a ser depositado: ");
                        double valorrecebe = ler.nextDouble();
                        saldo = saldo + valorrecebe;
                        System.out.println("Feito um deposito no valor de R$" + valorrecebe + " na sua conta!" );
                        System.out.println("\n");
                        break;
                    case 3:
                        System.out.println("Insira o valor a ser sacado: ");
                        double valorsaque = ler.nextDouble();
                        saldo -= valorsaque;
                        System.out.println("Feito um saque no valor de R$" + valorsaque + " na sua conta!" );
                        break;
                    case 0:
                        System.out.println("Sessão encerrada, obrigado.");
                        break;
                    default:
                        System.out.println("Opção invalida, tente novamente");
                        System.out.println("\n");
                        break;
                }
            } while (opcao != 0); // Continua o looping enquanto a opção não for igual a 0

        }

    }
}
