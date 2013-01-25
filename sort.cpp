
using namespace std;

bool lt(T x, T y){
	return x < y;
}

bool gt(T x, T y){
	return x > y;
}

void printArr(T* arr, size_t len, size_t start = 0){
	for(size_t i = start; i < len; i++){
		cout << arr[i] << endl;
	}
}

void binarySort(T* arr, size_t len, ORDER ord){
	BinaryTree bt(arr, len);
	bt.toArray(arr);
}

void selSort(T* arr, size_t len, ORDER ord){

	Evaluation eval;
	eval = (ord == ASC) ? &gt<T> : &lt<T>;
	// Start from end of array
	for(size_t i = len -1; i > 0; i--){

		T target = 0;
		// Iterate from start till we reach current index
		for(size_t j = 1; j <= i; j++){
			if(eval(arr[j], arr[target]))
				target = j;
		}
		T temp = arr[i];
		arr[i] = arr[target];
		arr[target] = temp;

	}


}

void bubbleSort(T* arr, size_t len){
	while(true){
		bool swapped = false;
		for(size_t i = 1; i < len; i++){
			if(arr[i-1] < arr[i]){
				T temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;
				swapped = true;
			}
		}
		if(swapped == false) break;
	}
}

void insertionSort(T* arr, size_t len, ORDER ord){
	Evaluation eval = (ord == ASC) ? gt : lt;
	for(size_t i = 1; i < len; i++){
		size_t j = i;
		while(j > 0 && eval(arr[j - 1], arr[j])){
			T temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}

}

void quickSort(T* arr, size_t left, size_t right, ORDER ord){

	size_t i = left, j = right;
	T pivot = arr[(i+j) >> 1];
	cout << "------------------------------------------------------------------\n";
	cout << "Quicksort called between " << left << " and " << right << " with pivot " << pivot << endl;

	Evaluation eval_i = (ord == ASC) ? lt : gt;
	Evaluation eval_j = (ord == ASC) ? gt : lt;

	while(i <= j){
		while(eval_i(arr[i], pivot))
			i++;
		while(eval_j(arr[j], pivot))
			j--;
		if(i <= j){
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	printArr(arr, right + 1, left);
	if(i < right){
		quickSort(arr, i, right, ord);
	}
	if(j > left){
		quickSort(arr, left, j, ord);
	}
}

