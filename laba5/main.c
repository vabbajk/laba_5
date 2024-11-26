#include "Header.h"

void Solution_1() {
    printf("������� ������ ������� : ");
    int size;
    Input_one_digit(&size);

    printf("����� ����� ����� ������� �� ������? (1 - ������, 2 - ���������)\n");
    char c;

    do {
        c = getch();

        if (c != '1' && c != '2' && c != '3') {
            printf("������� ���� �� ������������ ������!!!\n");
        }
        else {
            break;
        }
    } while (1);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("������ ��������� ������\n");
        return;
    }

    switch (c) {

        case '1':
            for (int i = 0; i < size; i++) { int k; Input_one_digit(&k); arr[i] = k; }
            break;

        case '2':

                Input_int_natural_array_rand(arr, size);
                printf("��� ��� ������ : ");
                for (int i = 0; i < size; i++) { printf("%d ", arr[i]); }
                printf("\n");

            break;

        case '3':

            for (int i = 1; i <= size; i++) { arr[i-1] = i; }
    }

    for (int i = 0; i < size; i++)
    {
        int res;
        check_na_prostotu(arr[i], &res);
        if (!res)
        {
            for (int j = i; j < size - 1; j++) { arr[j] = arr[j + 1]; }
            size--;

        }
    }

    int res;
    check_na_prostotu(arr[size-1], &res);
    if (!res){size--;}


    printf("��������� : ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
}

void Solution_2() {
    int a[1][2];
    printf("������� ������ ������� (N M) ����� ������: ");
    Input_matrix(&a, 1, 2);

    int n = a[0][0], m = a[0][1];

    printf("����� ����� ����� ������� �� ������? (1 - ������, 2 - ���������, 3 - �� �������):\n");
    char c;
    do {
        c = getch();
        if (c != '1' && c != '2' && c != '3') {
            printf("������� ���� �� ������������ ������!!!\n");
        }
    } while (c != '1' && c != '2' && c != '3');

    int** arr = (int**)malloc(n * sizeof(int*));
    if (arr == NULL) {
        printf("������ ��������� ������ ��� ����� �������\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m * sizeof(int));
        if (arr[i] == NULL) {
            printf("������ ��������� ������ ��� ������ %d\n", i);
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return;
        }
    }

    switch (c) {
    case '1':
        Input_matrix_dynamic(arr, n, m);
        printf("��� ���� �������:\n");
        Print_matrix_dynamic(arr, n, m);
        break;
    case '2':
        Generate_matrix_dynamic(arr, n, m);
        printf("��� ���� �������:\n");
        Print_matrix_dynamic(arr, n, m);
        break;
    case '3':
        Generate_matrix_by_order_dynamic(arr, n, m);
        printf("��� ���� �������:\n");
        Print_matrix_dynamic(arr, n, m);
        break;
    }

    printf("\n");

    int* min_in_col = (int*)malloc(m * sizeof(int));
    int* max_in_row = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++) {
        int mn = arr[0][i];
        for (int j = 0; j < n; j++) {
            if (arr[j][i] < mn) {
                mn = arr[j][i];
            }
        }
        min_in_col[i] = mn;
    }

    for (int i = 0; i < n; i++) {
        int mx = arr[i][0];
        for (int j = 1; j < m; j++) {
            if (arr[i][j] > mx) {
                mx = arr[i][j];
            }
        }
        max_in_row[i] = mx;
    }

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == max_in_row[i] && arr[i][j] == min_in_col[j]) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) break;
    }

    if (x != -1) {
        printf("�������� ����� ������� �� ������� (%d, %d) � ����� \n\n", x + 1, y + 1, arr[x][y]);
        for (int i = x; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = arr[i + 1][j];
            }
        }
        n--;
        printf("������� ����� �������� ������:\n");
        Print_matrix_dynamic(arr, n, m);
    }
    else {
        printf("�������� ����� �� �������.\n");
    }

    free(min_in_col);
    free(max_in_row);
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

void Solution_3() {
    printf("������� ������ ������� (���������� �����): ");
    int n;
    Input_one_digit(&n);

    int** arr = (int**)malloc(n * sizeof(int*));

    if (arr == NULL) {
        printf("������ ��������� ������\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("������� ����� ��� ������ %d (������������ ���� �����):\n", i + 1);


        int initial_size = 10;
        int* row = (int*)malloc(initial_size * sizeof(int));
        if (row == NULL) {
            printf("������ ��������� ������ ��� ������ %d\n", i + 1);
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return;
        }

        int size = 0;
        while (1) {
            int val;
            Input_one_digit(&val);

            if (val == 0) break;

            if (size >= initial_size) {
                initial_size++;
                int* new_row = (int*)realloc(row, initial_size * sizeof(int));
                if (new_row == NULL) {
                    printf("������ ����������������� ������\n");
                    free(row);
                    for (int j = 0; j < i; j++) {
                        free(arr[j]);
                    }
                    free(arr);
                    return;
                }
                row = new_row;
            }
            row[size++] = val;
        }

 
        row[size] = 0;
        arr[i] = (int*)realloc(row, (size + 1) * sizeof(int));
    }

    printf("������� ��������� ��������: ");
    int threshold;
    Input_one_digit(&threshold);

    printf("������������ ������:\n");
    for (int i = 0; i < n; i++) {
        int* row = arr[i];
        int size = 0;
        while (row[size] != 0) {
            if (row[size] <= threshold) {
                printf("%d ", row[size]);
            }
            size++;
        }
        printf("0\n"); 
        free(arr[i]); 
    }

    free(arr);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    while (1)
    {


        printf("����� ������ 5-�� ���� �� ������ ���������? (������� 1, 2 ��� 3)\n");

        char c;

        do
        {
            c = getch();

            if (c != '1' && c != '2' && c != '3')
            {
                printf("������� ���� �� ������������ ������!!!\n");
            }
            else
            {
                break;
            }
        } while (1);

        switch (c) {
        case '1':
            Solution_1();
            break;
        case '2':
            Solution_2();
            break;
        case '3':
            Solution_3();
            break;
        }
    }
}