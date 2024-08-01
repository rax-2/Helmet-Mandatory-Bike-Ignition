
int on()
{
  return 1;
}

int off()
{
  return 0;
}


int ReadIr(int a) {
  int data = digitalRead(a);
  if (data == 0)
  {
    return 1;
  }
  else if (data == 1)
  {
    return 0;
  }
  else
  {
    return 9;
  }
}
