// This file is MACHINE GENERATED! Do not edit.

#ifndef TENSORFLOW_CC_OPS_LINALG_OPS_H_
#define TENSORFLOW_CC_OPS_LINALG_OPS_H_

#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/graph/graph_def_builder.h"
#include "tensorflow/core/lib/gtl/array_slice.h"
#include "tensorflow/core/public/tensor.h"
#include "tensorflow/core/public/tensor_shape.h"

namespace tensorflow {
namespace ops {

// These add a node to the graph from opts.
//
// Note for "NodeOut" inputs, you will typically either pass
// * a {Node*, int index} (to pass the index-th output of that node), or
// * a Node* (to pass the first output of that node).


// Calculates the Cholesky decomposition of a batch of square matrices.
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices, with the same constraints as the single matrix Cholesky
// decomposition above. The output is a tensor of the same shape as the input
// containing the Cholesky decompositions for all input submatrices `[..., :, :]`.
//
// Arguments:
// * input: Shape is `[..., M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[..., M, M]`.
Node* BatchCholesky(NodeOut input, const GraphDefBuilder::Options& opts);

// Calculates the determinants for a batch of square matrices.
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices. The output is a 1-D tensor containing the determinants
// for all input submatrices `[..., :, :]`.
//
// Arguments:
// * input: Shape is `[..., M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[...]`.
Node* BatchMatrixDeterminant(NodeOut input, const GraphDefBuilder::Options&
                             opts);

// Calculates the inverse of square invertible matrices.
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices. The output is a tensor of the same shape as the input
// containing the inverse for all input submatrices `[..., :, :]`.
//
// The op uses the Cholesky decomposition if the matrices are symmetric positive
// definite and LU decomposition with partial pivoting otherwise.
//
// If a matrix is not invertible there is no guarantee what the op does. It
// may detect the condition and raise an exception or it may simply return a
// garbage result.
//
// Arguments:
// * input: Shape is `[..., M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[..., M, M]`.
Node* BatchMatrixInverse(NodeOut input, const GraphDefBuilder::Options& opts);

// Solves systems of linear equations. Checks for invertibility.
//
// Matrix is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices. Rhs is a tensor of shape
// `[..., M, K]`. The output is a tensor shape `[..., M, K]` where each output
// matrix satisfies matrix[..., :, :] * output[..., :, :] = rhs[..., :, :].
//
// Arguments:
// * matrix: Shape is `[..., M, M]`.
// * rhs: Shape is `[..., M, K]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[..., M, K]`.
Node* BatchMatrixSolve(NodeOut matrix, NodeOut rhs, const
                       GraphDefBuilder::Options& opts);

// Solves systems of linear equations with upper or lower triangular matrices by
//
// backsubstitution.
//
// `matrix` is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions form
// square matrices. If `lower` is `True` then the strictly upper triangular part
// of each inner-most matrix is ignored. If `lower` is False then the strictly
// lower triangular part of each inner-most matrix is ignored. `rhs` is a tensor
// of shape [..., M, K]`.
//
// The output is a tensor of shape `[..., M, K]`. If `lower` is `True` then the
// output satisfies
// \\(\sum_{k=0}^{i}\\) matrix[..., i, k] * output[..., k, j] = rhs[..., i, j].
// If `lower` is false then the strictly then the output satisfies
// \\(sum_{k=i}^{K-1}\\) matrix[..., i, k] * output[..., k, j] = rhs[..., i, j].
//
// Arguments:
// * matrix: Shape is `[..., M, M]`.
// * rhs: Shape is `[..., M, K]`.
// * opts:
//   .WithAttr("lower", bool): Defaults to true.
//     Boolean indicating whether matrix is lower or upper triangular.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[..., M, K]`.
Node* BatchMatrixTriangularSolve(NodeOut matrix, NodeOut rhs, const
                                 GraphDefBuilder::Options& opts);

// Calculates the Eigen Decomposition of a batch of square self-adjoint matrices.
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices, with the same constraints as the single matrix
// SelfAdjointEig.
//
// The result is a '[..., M+1, M] matrix with [..., 0,:] containing the
// eigenvalues, and subsequent [...,1:, :] containing the eigenvectors.
//
// Arguments:
// * input: Shape is `[..., M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[..., M+1, M]`.
Node* BatchSelfAdjointEig(NodeOut input, const GraphDefBuilder::Options& opts);

// Calculates the Cholesky decomposition of a square matrix.
//
// The input has to be symmetric and positive definite. Only the lower-triangular
// part of the input will be used for this operation. The upper-triangular part
// will not be read.
//
// The result is the lower-triangular matrix of the Cholesky decomposition of the
// input.
//
// Arguments:
// * input: Shape is `[M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[M, M]`.
Node* Cholesky(NodeOut input, const GraphDefBuilder::Options& opts);

// Calculates the determinant of a square matrix.
//
// Arguments:
// * input: A tensor of shape `[M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// A scalar, equal to the determinant of the input.
Node* MatrixDeterminant(NodeOut input, const GraphDefBuilder::Options& opts);

// Calculates the inverse of a square invertible matrix.
//
// The op uses the Cholesky decomposition if the matrix is symmetric positive
// definite and LU decomposition with partial pivoting otherwise.
//
// If the matrix is not invertible there is no guarantee what the op does. It
// may detect the condition and raise an exception or it may simply return a
// garbage result.
//
// Arguments:
// * input: Shape is `[M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[M, M]` containing the matrix inverse of the input.
Node* MatrixInverse(NodeOut input, const GraphDefBuilder::Options& opts);

// Solves a system of linear equations. Checks for invertibility.
//
// Arguments:
// * matrix: Shape is `[M, M]`.
// * rhs: Shape is `[M, K]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[M, K]` containing the tensor that solves
// matrix * output = rhs.
Node* MatrixSolve(NodeOut matrix, NodeOut rhs, const GraphDefBuilder::Options&
                  opts);

// Solves a system of linear equations with an upper or lower triangular matrix by
//
// backsubstitution.
//
// `matrix` is a matrix of shape `[M, M]`. If `lower` is `True` then the strictly
// upper triangular part of `matrix` is ignored. If `lower` is False then the
// strictly lower triangular part of `matrix` is ignored. `rhs` is a matrix of
// shape [M, K]`.
//
// The output is a matrix of shape `[M, K]`. If `lower` is `True` then the output
// satisfies \\(\sum_{k=0}^{i}\\) matrix[i, k] * output[k, j] = rhs[i, j].
// If `lower` is false then output satisfies
// \\(\sum_{k=i}^{K-1}\\) matrix[i, k] * output[k, j] = rhs[i, j].
//
// Arguments:
// * matrix: Shape is `[M, M]`.
// * rhs: Shape is `[M, K]`.
// * opts:
//   .WithAttr("lower", bool): Defaults to true.
//     Boolean indicating whether matrix is lower or upper triangular.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[M, K]`.
Node* MatrixTriangularSolve(NodeOut matrix, NodeOut rhs, const
                            GraphDefBuilder::Options& opts);

// Calculates the Eigen Decomposition of a square Self-Adjoint matrix.
//
// Only the lower-triangular part of the input will be used in this case. The
// upper-triangular part will not be read.
//
// The result is a M+1 x M matrix whose first row is the eigenvalues, and
// subsequent rows are eigenvectors.
//
// Arguments:
// * input: Shape is `[M, M]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Shape is `[M+1, M]`.
Node* SelfAdjointEig(NodeOut input, const GraphDefBuilder::Options& opts);

}  // namespace ops
}  // namespace tensorflow

#endif  // TENSORFLOW_CC_OPS_LINALG_OPS_H_