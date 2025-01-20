/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:55:00 by chdonnat          #+#    #+#             */
/*   Updated: 2025/01/20 08:57:17 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// // Fonction pour vérifier si un nombre existe déjà dans le tableau
// int exists_in_array(int *array, int size, int value) {
//     for (int i = 0; i < size; i++) {
//         if (array[i] == value) {
//             return 1; // Le nombre existe déjà
//         }
//     }
//     return 0; // Le nombre n'existe pas
// }

// int main(int argc, char *argv[]) {
//     // Vérification du nombre d'arguments
//     if (argc != 2) {
//         printf("Usage: %s <quantite de nombres>\n", argv[0]);
//         return 1;
//     }

//     // Conversion de l'argument en entier
//     int n = atoi(argv[1]);
//     if (n <= 0) {
//         printf("Veuillez entrer un nombre entier positif.\n");
//         return 1;
//     }

//     // Allocation dynamique pour stocker les nombres uniques
//     int *numbers = (int *)malloc(n * sizeof(int));
//     if (numbers == NULL) {
//         printf("Erreur d'allocation memoire.\n");
//         return 1;
//     }

//     // Initialisation du générateur de nombres aléatoires
//     srand(time(NULL));

//     int count = 0;
//     while (count < n) {
//         int random_number = rand() % (n * 10); // Génère un nombre aléatoire
//         if (!exists_in_array(numbers, count, random_number)) {
//             numbers[count] = random_number;
//             count++;
//         }
//     }

//     // Affichage des nombres générés
//     for (int i = 0; i < n; i++) {
//         printf("%d", numbers[i]);
//         if (i < n - 1) {
//             printf(" ");
//         }
//     }
//     printf("\n");

//     // Libération de la mémoire allouée
//     free(numbers);

//     return 0;
// }
