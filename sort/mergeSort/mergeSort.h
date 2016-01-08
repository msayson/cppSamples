// Requires T to implement "<" operator
// Requires startLeft <= startRight <= end
template<class T>
void merge(T* list, int startLeft, int startRight, int end) {
   int posLeft = startLeft;
   int posRight = startRight;

   int posTemp = 0;
   T* tempList = new T[end-startLeft+1];
   while (posLeft < startRight && posRight <= end) {
      if (list[posLeft] < list[posRight]) {
         tempList[posTemp++] = list[posLeft++];
      } else {
         tempList[posTemp++] = list[posRight++];
      }
   }
   while (posLeft < startRight) {
      tempList[posTemp++] = list[posLeft++];
   }
   while (posRight <= end) {
      tempList[posTemp++] = list[posRight++];
   }
   for (int i=startLeft; i<=end; i++) {
      list[i] = tempList[i-startLeft];
   }
   delete[] tempList;
}

// Requires T to implement "<" operator
template<class T>
void mergeSort(T* list, int start, int end) {
   if (start < end) {
      int endLeft = (start + end)/2;
      mergeSort(list, start, endLeft);    //mergeSort left
      mergeSort(list, endLeft+1, end);    //mergeSort right
      merge(list, start, endLeft+1, end); //merge sorted lists
   }
}
