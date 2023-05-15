program matrix_vector_multiplication
  ! pra nao tipificar baseado no nome da var
  implicit none
  
  integer, parameter :: m = 1000, n = 1000 ! size of matrix A (m x n)
  real, dimension(:,:), allocatable :: A   ! matrix A
  real, dimension(:), allocatable :: x, b  ! vectors x and b
  real :: start, finish, elapsed           ! variables to measure time
  integer :: i, j                          ! loop indices
  
  ! allocate memory for matrix A and vectors x and b
  allocate(A(m,n), x(n), b(m))
  
  ! initialize matrix A with random values between 0 and 1
  call random_number(A)
  
  ! initialize vector x with random values between 0 and 1
  call random_number(x)
  
  ! measure the time it takes to perform the matrix-vector multiplication
  call cpu_time(start)
  
  b = matmul(A, x)
  
  call cpu_time(finish)
  elapsed = finish - start
  
  ! write the result to a CSV file
  open(1, file='result.csv', status='replace')
  do i = 1, m
     write(1, '(f6.2)', advance='no') b(i)
     do j = 2, n
        write(1, '(f6.2)', advance='no') b(i)
     end do
     write(1, *)
  end do
  close(1)
  
  ! print the elapsed time
  write(*,*) "Elapsed time: ", elapsed, " seconds"
  
  ! deallocate memory
  deallocate(A, x, b)
  
end program matrix_vector_multiplication
