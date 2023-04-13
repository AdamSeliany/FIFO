#include <stdio.h>
#include<stdbool.h>
/*       ADAM SELIANI G13         */
int references[1000]; //Spécifie la taille maximale du tableau pour stocker la référence saisie par l'utilisateur
int memory[];//tableau vide pour stocke les cadere dans ce cas il ya 2 cadre => size de cette memoire physique est 2
int defaultDePage = 0;//Un compteur pour stocker le nombre de fois qu'un DP a été effectué
int fifo_pointer = 0;

int entrezLesReference(int n) {
    int i;
    printf("Entrez les references : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &references[i]);
    }
    return n;
}

bool siPageExiste(int page, int k) {
    int i;
    for (i = 0; i < k; i++) {
        if (memory[i] == page) /*exemple => page = 3 , k = 2cadre , i=0 =>memoire[0]=0 , le cadre 1 => si le cadre 1 contienr page 3
        return true else DO le meme avec cadre 2   si nest pas existe en les deux cadre DONC return false       */{

            return true;
        }
    }
    return false;
}

void add_page(int page, int n) {
    memory[fifo_pointer] = page;//stratigie fifo
    fifo_pointer = (fifo_pointer + 1) % n;// l'opérateur modulo % avec n pour assurer que le pointeur reste dans les limites du tableau
}

int main() {
    int n, k, i, j, page;
    printf("Entrez la longueur de la chaine de reference : ");
    scanf("%d", &n);
    printf("Entrez le nombre de cadres de page : ");
    scanf("%d", &k);
    n = entrezLesReference(n);//stocker la valeur qui scaner dans le variable n de la fonction 'entrezLesReference'
    for (i = 0; i < k; i++) {
                memory[i] = -1;//Les valeurs des deux cadres seront faites -1.
                // -1 est juste un choix, vous pouvez choisir n'importe quel nombre
    }
    printf("Resultat :\n DP|C1|C2\n");
    for (i = 0; i < n; i++) {
        page = references[i];//references[i] contient les refernce references[0] = 0 , references[4]=3 =>page=3 par exemple
        if (siPageExiste(page, k)==false) /* <- Si la page n'existe pas*/{
            defaultDePage++;
            add_page(page, k);
            printf(" D |");//nouvelle page = DP
        } else {
            printf("   |");//si il existe donc n'est pas de DP
        }
        for (j = 0; j < k; j++) /*counter pour les cadre  */{
            if (memory[j] == -1) {
                printf(" "); //Cela signifie que le cadre est actuellement vide
            } else {
                printf("%d", memory[j]);//Imprimer la valeur stockée dans le cadre
            }
            printf(" |");
        }
        printf("\n");//nnouvelle lige pour next page
    }
    printf("Nombre de defauts de page : %d\n", defaultDePage); //nbr total de default de page
    return 0;
}
