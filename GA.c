#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generation_counter = 0;
int decimal_power = 9;
int decimal_power_yeni_hesap = 9;
struct n{
    int data;
    struct m *genes;
    struct n *next;
};
typedef struct n node_fitness;

struct m{
    int gen;
    struct m *next;
};
typedef struct m node_genes;

int FitnessCalculator(int powerOf){
    int base = 1;
    while (powerOf >0){
        base = base * 2;
        powerOf--;
    }
    return base;
}

node_fitness *best_chromosome = NULL;

void best_chro(node_fitness *best, node_fitness *root, int gen_number){
    if (best_chromosome == NULL){
        node_genes *temporary_for_root = NULL;
        node_genes *temporary_for_best = NULL;
        best_chromosome = (node_fitness *)malloc(sizeof(node_fitness));
        best_chromosome ->genes = (node_genes *)malloc(sizeof(node_genes));
        best_chromosome ->genes ->gen = root ->genes ->gen;
        temporary_for_best = root ->genes;
        temporary_for_root = root ->genes;
        best_chromosome ->genes ->next = NULL;
        best_chromosome ->genes = best_chromosome ->genes ->next;
        root ->genes = root ->genes ->next;
        while (gen_number > 0){
            best_chromosome ->genes = (node_genes *)malloc(sizeof(node_genes));
            best_chromosome ->genes ->gen = root ->genes ->gen;
            best_chromosome ->genes ->next = NULL;
            best_chromosome ->genes = best_chromosome ->genes ->next;
            root ->genes = root ->genes ->next;
            gen_number--;
        }
        best_chromosome ->data = root ->data;
        best_chromosome ->genes = temporary_for_best ;
        root ->genes = temporary_for_root ;
    }
    else if (best_chromosome != NULL && (best_chromosome ->data) > (root ->data)){
        node_genes *temporary_for_root = NULL;
        node_genes *temporary_for_best = NULL;
        temporary_for_best = root ->genes;
        temporary_for_root = root ->genes;
        while (best_chromosome ->genes != NULL){
            best_chromosome ->genes ->gen = root ->genes ->gen;
            best_chromosome ->genes = best_chromosome ->genes ->next;
            root ->genes = root ->genes ->next;
        }
        best_chromosome ->data = root ->data;
        best_chromosome ->genes = temporary_for_best ;
        root ->genes = temporary_for_root ;
    }
}


node_fitness *addnode_fitness(node_fitness *r,char *gen_line, int powerOf){
    char *strtok_variable;
    int decimal_of_bits = 0, i, gen_sayisi;
    gen_sayisi = powerOf;
    if (r == NULL){
        r = (node_fitness *)malloc(sizeof(node_fitness));
        r ->next = NULL;
        r ->genes = NULL;
        strtok_variable = strtok(gen_line, ":");

        for(i = 0;i <= gen_sayisi; i++){
            if (r ->genes == NULL){
                r ->genes = (node_genes *)malloc(sizeof(node_genes));
                r ->genes ->next = NULL;
                r ->genes ->gen = atoi(strtok_variable);
                if (strcmp(strtok_variable, "1") == 0){
                    decimal_of_bits += FitnessCalculator(powerOf);
                    powerOf--;
                }
                else{
                    powerOf--;
                }
            }
            else if(r ->genes ->next == NULL){
                r ->genes ->next = (node_genes *)malloc(sizeof(node_genes));
                r ->genes ->next ->next = NULL;
                r ->genes ->next ->gen = atoi(strtok_variable);
                if (strcmp(strtok_variable, "1") == 0){
                    decimal_of_bits += FitnessCalculator(powerOf);
                    powerOf--;
                }
                else{
                    powerOf--;
                }
            }
            else{
                node_genes *iterator_for_genes = (node_genes *)malloc(sizeof(node_genes));
                iterator_for_genes = r ->genes;
                while (iterator_for_genes ->next != NULL){
                    iterator_for_genes = iterator_for_genes ->next;
                }
                node_genes *gecici_node = (node_genes *)malloc(sizeof(node_genes));
                gecici_node ->next = iterator_for_genes ->next;
                iterator_for_genes ->next = gecici_node;
                gecici_node ->gen = atoi(strtok_variable);
                if (strcmp(strtok_variable, "1") == 0){
                    decimal_of_bits += FitnessCalculator(powerOf);
                    powerOf--;
                }
                else{
                    powerOf--;
                }
            }
            if (i != 9){
                strtok_variable = strtok(NULL ,":");
            }
            else{}
        }
        r ->data = decimal_of_bits;

        return r;
    }

    else if (r ->next == NULL){
        node_fitness *gecici_node = (node_fitness *)malloc(sizeof(node_fitness));
        gecici_node ->next = r ->next;
        r ->next = gecici_node;
        gecici_node ->genes = NULL;
        strtok_variable = strtok(gen_line, ":");

        for(i = 0;i <= gen_sayisi; i++){
            if (gecici_node ->genes == NULL){
                gecici_node ->genes = (node_genes *)malloc(sizeof(node_genes));
                gecici_node ->genes ->next = NULL;
                gecici_node ->genes ->gen = atoi(strtok_variable);
                if (strcmp(strtok_variable, "1") == 0){
                    decimal_of_bits += FitnessCalculator(powerOf);
                    powerOf--;
                }
                else{
                    powerOf--;
                }
            }
            else if(gecici_node ->genes ->next == NULL){
                gecici_node ->genes ->next = (node_genes *)malloc(sizeof(node_genes));
                gecici_node ->genes ->next ->next = NULL;
                gecici_node ->genes ->next ->gen = atoi(strtok_variable);
                if (strcmp(strtok_variable, "1") == 0){
                    decimal_of_bits += FitnessCalculator(powerOf);
                    powerOf--;
                }
                else{
                    powerOf--;
                }
            }
            else{
                node_genes *iterator_for_genes = (node_genes *)malloc(sizeof(node_genes));
                iterator_for_genes = gecici_node ->genes;
                while (iterator_for_genes ->next != NULL){
                    iterator_for_genes = iterator_for_genes ->next;
                }
                node_genes *gecici_node = (node_genes *)malloc(sizeof(node_genes));
                gecici_node ->next = iterator_for_genes ->next;
                iterator_for_genes ->next = gecici_node;
                gecici_node ->gen = atoi(strtok_variable);
                if (strcmp(strtok_variable, "1") == 0){
                    decimal_of_bits += FitnessCalculator(powerOf);
                    powerOf--;
                }
                else{
                    powerOf--;
                }
            }
            if (i != 9){
                strtok_variable = strtok(NULL ,":");
            }
            else{}
        }
        gecici_node ->data = decimal_of_bits;

        return r;
    }

    node_fitness *iterator = (node_fitness *)malloc(sizeof(node_fitness));
    iterator = r;

    while(iterator ->next != NULL){
        iterator = iterator ->next;
    }
    node_fitness *gecici_node = (node_fitness *)malloc(sizeof(node_fitness));
    gecici_node ->next = iterator ->next;
    iterator ->next = gecici_node;
    gecici_node ->genes = NULL;
    strtok_variable = strtok(gen_line, ":");

    for(i = 0;i <= gen_sayisi; i++){
        if (gecici_node ->genes == NULL){
            gecici_node ->genes = (node_genes *)malloc(sizeof(node_genes));
            gecici_node ->genes ->next = NULL;
            gecici_node ->genes ->gen = atoi(strtok_variable);
            if (strcmp(strtok_variable, "1") == 0){
                decimal_of_bits += FitnessCalculator(powerOf);
                powerOf--;
            }
            else{
                powerOf--;
            }
        }
        else if(gecici_node ->genes ->next == NULL){
            gecici_node ->genes ->next = (node_genes *)malloc(sizeof(node_genes));
            gecici_node ->genes ->next ->next = NULL;
            gecici_node ->genes ->next ->gen = atoi(strtok_variable);
            if (strcmp(strtok_variable, "1") == 0){
                decimal_of_bits += FitnessCalculator(powerOf);
                powerOf--;
            }
            else{
                powerOf--;
            }
        }
        else{
            node_genes *iterator_for_genes = (node_genes *)malloc(sizeof(node_genes));
            iterator_for_genes = gecici_node ->genes;
            while (iterator_for_genes ->next != NULL){
                iterator_for_genes = iterator_for_genes ->next;
            }
            node_genes *gecici_node = (node_genes *)malloc(sizeof(node_genes));
            gecici_node ->next = iterator_for_genes ->next;
            iterator_for_genes ->next = gecici_node;
            gecici_node ->gen = atoi(strtok_variable);
            if (strcmp(strtok_variable, "1") == 0){
                decimal_of_bits += FitnessCalculator(powerOf);
                powerOf--;
            }
            else{
                powerOf--;
            }
        }
        if (i != 9){
            strtok_variable = strtok(NULL ,":");
        }
        else{}
    }
    gecici_node ->data = decimal_of_bits;

    return r;
}

void swap(node_fitness *a, node_fitness *b){
    node_fitness *temp =(node_fitness *)malloc(sizeof(node_fitness));
    temp ->data = a ->data;
    a ->data = b ->data;
    b ->data = temp ->data;
    temp ->genes = a->genes;
    a ->genes = b ->genes;
    b ->genes = temp ->genes;
}

void new_fitnesses(node_fitness *root,int powerOf){
    node_fitness *iterator = (node_fitness *)malloc(sizeof(node_fitness));
    node_genes *geri_don = (node_genes *)malloc(sizeof(node_genes));
    int power = powerOf;
    iterator = root;
    while(iterator != NULL){
        int decimal_of_bits = 0;
        powerOf = power;
        geri_don = iterator ->genes;
        while(iterator->genes != NULL){
            if(iterator->genes->gen == 1){
                decimal_of_bits += FitnessCalculator(powerOf);
                powerOf--;
            }
            else{
                powerOf--;
            }
            iterator ->genes = iterator ->genes ->next;
        }
        iterator ->data = decimal_of_bits;
        iterator ->genes = geri_don;
        iterator = iterator ->next;
    }
    iterator = root;
}

void bubbleSort(node_fitness *start) {
    int swapped;
    node_fitness *ptr1 = (node_fitness *)malloc(sizeof(node_fitness));
    node_fitness *lptr = NULL;

    if (start == NULL)
        return;
    do{
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr){
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void xover_their_genes(node_fitness *first_chrom, node_fitness *second_chrom, int start_gen, int finish_gen, int mutate_gen){
    int i, j = 1, temp;
    node_fitness *temporary = (node_fitness *)malloc(sizeof(node_fitness));
    node_fitness *temporary2 = (node_fitness *)malloc(sizeof(node_fitness));
    node_genes *geri_don =(node_genes *)malloc(sizeof(node_genes));
    node_genes *geri_don2 =(node_genes *)malloc(sizeof(node_genes));
    temporary = first_chrom, temporary2 = second_chrom, geri_don = first_chrom->genes, geri_don2 = second_chrom->genes;

    
    for (i = start_gen ; i <= finish_gen ; i++){
        while(j != start_gen){
            temporary ->genes = temporary ->genes->next;
            temporary2 ->genes = temporary2 ->genes->next;
            j++;
        }
        temp = temporary ->genes ->gen;
        temporary ->genes ->gen = temporary2 ->genes ->gen;
        temporary2 ->genes ->gen = temp;
        if(i != finish_gen){
            temporary ->genes = temporary ->genes ->next;
            temporary2 ->genes = temporary2 ->genes ->next;
        }
        else{}
    }
    temporary ->genes = geri_don;
    temporary2 ->genes = geri_don2;

    for(i = 1 ; i < mutate_gen ; i++){
        temporary ->genes = temporary ->genes ->next;
        temporary2 ->genes = temporary2 ->genes ->next;
    }
    if(temporary ->genes ->gen == 0){
        temporary ->genes ->gen = 1;
    }
    else{
        temporary ->genes ->gen = 0;
    }
    if(temporary2 ->genes ->gen == 0){
        temporary2 ->genes ->gen = 1;
    }
    else{
        temporary2 ->genes ->gen = 0;
    }
    temporary ->genes = geri_don;
    temporary2 ->genes = geri_don2;
}

void selection_funct(node_fitness *root, char *selection_text, char *xover_text, char *mutate_text){
    char *strtok_xover = strtok(xover_text, ":");
    int selection_chr_number1 , selection_chr_number2, i;
    int gen1_xover = atoi(strtok_xover); // xover gen number 1
    strtok_xover = strtok(NULL, "\n");
    char *strtok_selection = strtok(selection_text, ":");
    int gen2_xover = atoi(strtok_xover); // xover gen number 2
    int mutate_gen = atoi(mutate_text); // mutate gen number

    node_fitness *selection1 = (node_fitness *)malloc(sizeof(node_fitness));
    node_fitness *selection2 = (node_fitness *)malloc(sizeof(node_fitness));
    selection1 = root, selection2 = root;


    while(strtok_selection != NULL){
        selection_chr_number1 = atoi(strtok_selection);
        strtok_selection = strtok(NULL, " ");
        selection_chr_number2 = atoi(strtok_selection);
        for(i = 1; i < selection_chr_number1 ; i++){
            selection1 = selection1 ->next; // first selection chromosome
        }
        for(i = 1; i < selection_chr_number2 ; i++){
            selection2 = selection2 ->next; // second selection chromosome
        }
        xover_their_genes(selection1,selection2,gen1_xover,gen2_xover,mutate_gen);
        strtok_selection = strtok(NULL, ":");
        selection1 = root , selection2 = root;
    }
}

node_fitness* PrintingList(node_fitness *root, int generation_c){
    node_fitness *temporary = (node_fitness *)malloc(sizeof(node_fitness));
    node_genes *geri_don =(node_genes *)malloc(sizeof(node_genes));
    node_genes *geri_best = (node_genes *)malloc(sizeof(node_genes));
    geri_best = best_chromosome ->genes;
    temporary = root;
    printf("GENERATION :%d\n",generation_c);
    while (temporary != NULL){
        geri_don = temporary->genes;
        while(temporary ->genes != NULL){
            if(temporary ->genes ->next == NULL){
                printf("%d",temporary ->genes ->gen);
                temporary ->genes = temporary ->genes ->next;
            }
            else{
                printf("%d:",temporary ->genes ->gen);
                temporary ->genes = temporary ->genes ->next;
            }
        }
        printf(" -> ");
        printf("%d\n",temporary ->data);
        temporary->genes = geri_don;
        temporary = temporary ->next;
    }
    temporary = root;
    geri_don = temporary->genes;
    generation_counter++;
    printf("Best chromosome found so far: ");
    while(best_chromosome ->genes != NULL){
        if(best_chromosome ->genes ->next == NULL){
            printf("%d",best_chromosome ->genes ->gen);
            best_chromosome ->genes = best_chromosome ->genes ->next;
        }
        else{
            printf("%d:",best_chromosome ->genes ->gen);
            best_chromosome ->genes = best_chromosome ->genes ->next;
        }
    }
    printf(" -> %d\n",best_chromosome->data);
    temporary->genes = geri_don;
    best_chromosome ->genes = geri_best;
    return root;
}

int main(int argc, char** argv){
    FILE *population_ptr = fopen("population.txt","r");
    FILE *selection_ptr = fopen("selection.txt","r");
    FILE *xover_ptr = fopen("xover.txt","r");
    FILE *mutate_ptr = fopen("mutate.txt","r");
    node_fitness * root = NULL;
    int population_len = 0, selection_len = 0, xover_len = 0, mutate_len = 0;
    char *population_text, *selection_text, *xover_text, *mutate_text, *strtok_population, *strtok_selection, *strtok_mutate, *strtok_xover;
    decimal_power = (atoi(argv[1])-1), decimal_power_yeni_hesap = (atoi(argv[1])-1);
    int gen_num_for_best = (atoi(argv[1])-1);

    fseek(population_ptr,0,SEEK_END);
    population_len = ftell(population_ptr);
    fseek(population_ptr,0,SEEK_SET);

    fseek(selection_ptr,0,SEEK_END);
    selection_len = ftell(selection_ptr);
    fseek(selection_ptr,0,SEEK_SET);

    fseek(xover_ptr,0,SEEK_END);
    xover_len = ftell(xover_ptr);
    fseek(xover_ptr,0,SEEK_SET);

    fseek(mutate_ptr,0,SEEK_END);
    mutate_len = ftell(mutate_ptr);
    fseek(mutate_ptr,0,SEEK_SET);
    
    population_text = ((char *)malloc(sizeof(char) * population_len));
    selection_text = ((char *)malloc(sizeof(char) * selection_len));
    xover_text = ((char *)malloc(sizeof(char) * xover_len));
    mutate_text = ((char *)malloc(sizeof(char) * mutate_len));
    
    while(fgets(population_text,population_len,population_ptr) != NULL){
        strtok_population = strtok(population_text, "\n");
        root = addnode_fitness(root,strtok_population,decimal_power);
    }
    
    bubbleSort(root);
    best_chro(best_chromosome,root,gen_num_for_best);
    root = PrintingList(root,generation_counter);
    while(fgets(selection_text,selection_len,selection_ptr) != NULL){
        fgets(xover_text,xover_len,xover_ptr);
        fgets(mutate_text,mutate_len,mutate_ptr);
        strtok_selection = strtok(selection_text, "\n");
        strtok_xover = strtok(xover_text, "\n");
        strtok_mutate = strtok(mutate_text, "\n");
        selection_funct(root,selection_text,xover_text,mutate_text);
        new_fitnesses(root,decimal_power_yeni_hesap);
        bubbleSort(root);
        best_chro(best_chromosome,root,gen_num_for_best);
        root = PrintingList(root,generation_counter);
    }
	return 0;
}
