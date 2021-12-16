import numpy as np

# squared error 함수 구현
def squared_error(y, t):    
    return 0.5 * np.sum((y - t)**2)

def mean_squared_error(y, t):
    # vector input -> 1-row matrix 
    if y.ndim == 1:   # vector y.shape = (D,)
        t = t.reshape(1, t.size)  # t.shape = (1,D)
        y = y.reshape(1, y.size)  # y.shape = (1,D)

    # assumption: t.shape = y.shape = (N,D)
    # note: matrix 에 대하여 sum() 함수를 호출하면 전체 원소들의 합
    return 0.5 * ((y - t)**2).sum()/y.shape[0]

def cross_entropy_error_one_hot_1(y, t):
    delta = 1e-7
    return -np.sum(t * np.log(y + delta))

def cross_entropy_error_one_hot_2(y, t):
    delta = 1e-7
    return -np.log(y[t==1] + delta)

def cross_entropy_error_index(y, t):
    delta = 1e-7
    return -np.log(y[t] + delta)

def mean_cross_entropy_error(y, t):
    if y.dim == 1:
        y = y.reshape(1, y.size)
        t = t.reshape(1, t.size)
    delta = 1e-7
    return -np.sum(t * np.log(y + delta)) / y.shape[0]


t = np.array([0, 0, 1, 0, 0, 0, 0, 0, 0, 0])
y1 = np.array([0.1, 0.05, 0.6, 0.0, 0.05, 0.1, 0.0, 0.1, 0.0, 0.0])
y2 = np.array([0.1, 0.05, 0.1, 0.0, 0.05, 0.1, 0.0, 0.6, 0.0, 0.0])

print('CE of y1 = %.10f' % cross_entropy_error_one_hot_1(y1,t))
print('CE of y2 = %.10f' % cross_entropy_error_one_hot_1(y2,t))
