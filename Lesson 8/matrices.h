__DEVICE__ void matrix_matrix_multiply(float dst[][3], float a[][3], float b[][3]) {
    const int mat_dim = 3;
    for (int i = 0; i < mat_dim; ++i) {
        for (int j = 0; j < mat_dim; ++j) {
            float agg = 0;
            for (int k = 0; k < mat_dim; ++k) {
                agg += a[i][k] * b[k][j];
            }
            dst[i][j] = agg;
        }
    }
}

__DEVICE__ float3 matrix_vector_multiply(float a[3][3], float3 b) {
    const int mat_dim = 3;
    float in[3] = {b.x, b.y, b.z};
    float out[3] = {0.0};
    for (int i = 0; i < mat_dim; ++i) {
        for (int j = 0; j < mat_dim; ++j) {
            out[i] += a[i][j] * in[j];
        }
    }
    return make_float3(out[0], out[1], out[2]);
}

__DEVICE__ void matrix_copy(float dst[3][3], float src[3][3]) {
    const int mat_dim = 3;
    for (int i = 0; i < mat_dim; ++i) {
        for (int j = 0; j < mat_dim; ++j) {
            dst[i][j] = src[i][j];
        }
    }
}