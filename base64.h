#ifndef BASE64_NARISOK_GUARD
#define BASE64_NARISOK_GUARD

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// TODO description
/**
 * @brief 
 * Don't add terminal null at the end.
 * @param data_to_encode 
 * @param bytes_count 
 * @param encoded_destination 
 * @return size_t 
 */
size_t base64_encode(const unsigned char * data_to_encode, size_t bytes_count, char *encoded_destination);

// TODO description
/**
 * @brief 
 * Don't add terminal null at the end.
 * @param data_to_encode 
 * @param bytes_count 
 * @param encoded_destination 
 * @return size_t 
 */
size_t base64url_encode(const unsigned char * data_to_encode, size_t bytes_count, char *encoded_destination);


/**
 * @brief decode base64 and base64url ecncoded data 
 * make sure the encoded data is correct base64 and contains paddings
 * 
 * @param encoded_data encoded data must contain paddings, ignores the last bytes if they are not padded 
 * @param bytes_count byte count of encoded data
 * @param decoded_destination make sure that free space in bytes greater than or equal to base64_min_decoded_size or base64_max_decoded_size
 * @return returns the number of bytes that have been encoded
 */
size_t base64_decode(const char *encoded_data, size_t bytes_count, unsigned char *decoded_destination);

// TODO ignore bad symbols and throw if not correct syntax
/**
 * @brief decode base64 and base64url ecncoded data 
 * omission of all incorrect and syntactic errors of coded data
 * 
 * @param encoded_data encoded data 
 * @param bytes_count byte count of encoded data
 * @param decoded_destination make sure that free space in bytes greater than or equal to base64_min_decoded_size or base64_max_decoded_size
 * @return returns the number of bytes that have been encoded 
 */
size_t base64_decode_safe(const char *encoded_data, size_t bytes_count, unsigned char *decoded_destination);

/**
 * @brief Calculates the maximum number of bytes to decode.
 * There is no guarantee that this number of bytes will be received after decoding.
 * There is a guarantee that the number of bytes received will not exceed this number.
 * 3:4
 * 
 * @param encoded_bytes_count 
 * @return Returns the number of bytes in which the decoded code should fit
 */
size_t base64_calculate_decoded_size(size_t encoded_bytes_count);

/**
 * @brief Calculates the number of bytes to encode.
 * 4:3
 * 
 * @param decoded_bytes_count 
 * @return Returns the number of bytes required for encoded information.
 */
size_t base64_calculate_encoded_size(size_t decoded_bytes_count);

/**
 * @brief check the base64 encoded data
 * 
 * @param encoded_data encoded data
 * @param bytes_count byte count of encoded data 
 * @return 1 if correct otherwise 0  
 */
int base64_check(const char *encoded_data, size_t bytes_count); //TODO realize this function

/**
 * @brief check the base64url encoded data
 * 
 * @param encoded_data 
 * @param bytes_count
 * @return 1 if correct otherwise 0 
 */
int base64url_check(const char *encoded_data, size_t bytes_count); //TODO realize this function

#ifdef __cplusplus
}
#endif

#endif