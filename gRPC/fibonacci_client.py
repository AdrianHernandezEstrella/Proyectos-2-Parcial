import grpc
import fibonacci_pb2
import fibonacci_pb2_grpc


def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = fibonacci_pb2_grpc.FibonacciCalculatorStub(channel)
        response = stub.CalculateFibonacci(fibonacci_pb2.FibonacciRequest(n=20))
        print("Fibonacci(10) = {}".format(response.result))


if __name__ == '__main__':
    run()
