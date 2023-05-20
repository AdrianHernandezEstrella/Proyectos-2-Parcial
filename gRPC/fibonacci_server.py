import concurrent.futures
import grpc
import fibonacci_pb2
import fibonacci_pb2_grpc


class FibonacciCalculatorServicer(fibonacci_pb2_grpc.FibonacciCalculatorServicer):
    def CalculateFibonacci(self, request, context):
        if request.n == 0:
            return fibonacci_pb2.FibonacciResponse(result=0)
        elif request.n == 1:
            return fibonacci_pb2.FibonacciResponse(result=1)
        else:
            a, b = 0, 1
            for _ in range(request.n - 1):
                a, b = b, a + b
            return fibonacci_pb2.FibonacciResponse(result=b)


def serve():
    server = grpc.server(concurrent.futures.ThreadPoolExecutor(max_workers=10))
    fibonacci_pb2_grpc.add_FibonacciCalculatorServicer_to_server(
        FibonacciCalculatorServicer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    serve()
