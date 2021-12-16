# 평균 제곱 오차(MSE)를 구현한다.

import numpy as np

# mean squared error 함수 구현
def mean_squared_error(y, t):
    # vector input -> 1-row matrix 
    if y.ndim == 1:   # vector y.shape = (D,)
        t = t.reshape(1, t.size)  # t.shape = (1,D)
        y = y.reshape(1, y.size)  # y.shape = (1,D)

    # assumption: t.shape = y.shape = (N,D)
    # note: matrix 에 대하여 sum() 함수를 호출하면 전체 원소들의 합
    print(y.shape[0])
    return 0.5 * np.sum(((y - t)**2))/y.shape[0]

t = np.array([0,0,1,0,0,0,0,0,0,0])
y1 = np.array([0.1, 0.05, 0.6, 0.0, 0.05, 0.1, 0.0, 0.1, 0.0, 0.0])
y2 = np.array([0.1, 0.05, 0.1, 0.0, 0.05, 0.1, 0.0, 0.6, 0.0, 0.0])

Y, T = np.vstack((y1, y2)), np.vstack((t, t))

print(mean_squared_error(y1, t))
print(mean_squared_error(y2, t))

print(mean_squared_error(Y, T))
