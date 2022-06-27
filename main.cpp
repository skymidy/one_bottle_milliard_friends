#include <iostream>
#include <vector>

void heapify(std::vector<int> &harr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && harr[l] > harr[largest])
        largest = l;

    if (r < n && harr[r] > harr[largest])
        largest = r;

    if (largest != i) {
        std::swap(harr[i], harr[largest]);

        heapify(harr, n, largest);
    }
}

void bubbleUp(std::vector<int> &harr, int i) {
    if (i == 0) return;

    int parent = (i - 1) / 2;

    if (harr[parent] < harr[i]) {
        std::swap(harr[parent], harr[i]);
        bubbleUp(harr, parent);
    }
}


void buildHeap(std::vector<int> &harr, int n) {

    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(harr, n, i);
    }
}

void solution(FILE *src, FILE *dest) {
    int n, m;
    fscanf(src, "%d %d\n", &n, &m);

    std::vector<int> harr;

    int a;
    for (int i = 0; i < n; ++i) {
        fscanf(src, "%d", &a);
        harr.push_back(a);
        bubbleUp(harr, i);
    }

    for (int i = 0; i < m; ++i) {
        harr[0] = harr[0] / 10;
        heapify(harr, n, 0);
    }

    long long answer = 0;
    for (int i: harr) {
        answer += i;
    }
    fprintf(dest, "%lld", answer);
}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    solution(in, out);

    fclose(in);
    fclose(out);
    return 0;
}
