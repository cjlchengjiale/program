void countsort(int* array,int n)
{
  int min = array[0],max = array[0];
  for(int i = 1;i<n;i++)
  {
    if(array[i]>max)
      max = array[i];
    if(array[i]<min)
      min = array[i];
  }
  int range = max - min + 1;
  //开辅助空间
  int* countarr = (int*)malloc(sizeof(int)*range);
  memset(countarr,0,sizeof(int)*range);
  for(int i = 0;i<n;i++)
  {
    countarr[array[i] - min]++;
  }
  //恢复数据
  int idx = 0;
  for(int i = 0;i<range;i++)
  {
    while(countarr[i]--)
    {
      array[idx++] = i + min;
    }
  }
  free(countarr);
}
