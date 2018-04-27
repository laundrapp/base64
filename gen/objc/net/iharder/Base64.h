//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: /Users/marcussmith/temp/base64/src/net/iharder/Base64.java
//

#include "J2ObjC_header.h"

#pragma push_macro("INCLUDE_ALL_NetIharderBase64")
#ifdef RESTRICT_NetIharderBase64
#define INCLUDE_ALL_NetIharderBase64 0
#else
#define INCLUDE_ALL_NetIharderBase64 1
#endif
#undef RESTRICT_NetIharderBase64

#if __has_feature(nullability)
#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wnullability-completeness"
#endif

#if !defined (NetIharderBase64_) && (INCLUDE_ALL_NetIharderBase64 || defined(INCLUDE_NetIharderBase64))
#define NetIharderBase64_

@class IOSByteArray;
@class JavaNioByteBuffer;
@class JavaNioCharBuffer;
@protocol JavaIoSerializable;

@interface NetIharderBase64 : NSObject

#pragma mark Public

/*!
 @brief Low-level access to decoding ASCII characters in
  the form of a byte array.
 <strong>Ignores GUNZIP option, if
  it's set.</strong> This is not generally a recommended method,
  although it is used internally as part of the decoding process.
  Special case: if len = 0, an empty array is returned. Still,
  if you need more speed and reduced memory footprint (and aren't
  gzipping), consider this method.
 @param source The Base64 encoded data
 @return decoded data
 @since 2.3.1
 */
+ (IOSByteArray *)decodeWithByteArray:(IOSByteArray *)source;

/*!
 @brief Low-level access to decoding ASCII characters in
  the form of a byte array.
 <strong>Ignores GUNZIP option, if
  it's set.</strong> This is not generally a recommended method,
  although it is used internally as part of the decoding process.
  Special case: if len = 0, an empty array is returned. Still,
  if you need more speed and reduced memory footprint (and aren't
  gzipping), consider this method.
 @param source The Base64 encoded data
 @param off The offset of where to begin decoding
 @param len The length of characters to decode
 @param options Can specify options such as alphabet type to use
 @return decoded data
 @throw java.io.IOExceptionIf bogus characters exist in source data
 @since 1.3
 */
+ (IOSByteArray *)decodeWithByteArray:(IOSByteArray *)source
                              withInt:(jint)off
                              withInt:(jint)len
                              withInt:(jint)options;

/*!
 @brief Decodes data from Base64 notation, automatically
  detecting gzip-compressed data and decompressing it.
 @param s the string to decode
 @return the decoded data
 @throw java.io.IOExceptionIf there is a problem
 @since 1.4
 */
+ (IOSByteArray *)decodeWithNSString:(NSString *)s;

/*!
 @brief Decodes data from Base64 notation, automatically
  detecting gzip-compressed data and decompressing it.
 @param s the string to decode
 @param options encode options such as URL_SAFE
 @return the decoded data
 @throw java.io.IOExceptionif there is an error
 @throw NullPointerExceptionif <tt>s</tt> is null
 @since 1.4
 */
+ (IOSByteArray *)decodeWithNSString:(NSString *)s
                             withInt:(jint)options;

/*!
 @brief Reads <tt>infile</tt> and decodes it to <tt>outfile</tt>.
 @param infile Input file
 @param outfile Output file
 @throw java.io.IOExceptionif there is an error
 @since 2.2
 */
+ (void)decodeFileToFileWithNSString:(NSString *)infile
                        withNSString:(NSString *)outfile;

/*!
 @brief Convenience method for reading a base64-encoded
  file and decoding it.
 <p>As of v 2.3, if there is a error,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned false, but
  in retrospect that's a pretty poor way to handle it.</p>
 @param filename Filename for reading encoded data
 @return decoded byte array
 @throw java.io.IOExceptionif there is an error
 @since 2.1
 */
+ (IOSByteArray *)decodeFromFileWithNSString:(NSString *)filename;

/*!
 @brief Convenience method for decoding data to a file.
 <p>As of v 2.3, if there is a error,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned false, but
  in retrospect that's a pretty poor way to handle it.</p>
 @param dataToDecode Base64-encoded data as a string
 @param filename Filename for saving decoded data
 @throw java.io.IOExceptionif there is an error
 @since 2.1
 */
+ (void)decodeToFileWithNSString:(NSString *)dataToDecode
                    withNSString:(NSString *)filename;

/*!
 @brief Attempts to decode Base64 data and deserialize a Java
  Object within.Returns <tt>null</tt> if there was an error.
 @param encodedObject The Base64 data to decode
 @return The decoded and deserialized object
 @throw NullPointerExceptionif encodedObject is null
 @throw java.io.IOExceptionif there is a general error
 @throw ClassNotFoundExceptionif the decoded object is of a 
          class that cannot be found by the JVM
 @since 1.5
 */
+ (id)decodeToObjectWithNSString:(NSString *)encodedObject;

/*!
 @brief Performs Base64 encoding on the <code>raw</code> ByteBuffer,
  writing it to the <code>encoded</code> ByteBuffer.
 This is an experimental feature. Currently it does not
  pass along any options (such as <code>DO_BREAK_LINES</code>
  or <code>GZIP</code>.
 @param raw input buffer
 @param encoded output buffer
 @since 2.3
 */
+ (void)encodeWithJavaNioByteBuffer:(JavaNioByteBuffer *)raw
              withJavaNioByteBuffer:(JavaNioByteBuffer *)encoded;

/*!
 @brief Performs Base64 encoding on the <code>raw</code> ByteBuffer,
  writing it to the <code>encoded</code> CharBuffer.
 This is an experimental feature. Currently it does not
  pass along any options (such as <code>DO_BREAK_LINES</code>
  or <code>GZIP</code>.
 @param raw input buffer
 @param encoded output buffer
 @since 2.3
 */
+ (void)encodeWithJavaNioByteBuffer:(JavaNioByteBuffer *)raw
              withJavaNioCharBuffer:(JavaNioCharBuffer *)encoded;

/*!
 @brief Encodes a byte array into Base64 notation.
 Does not GZip-compress data.
 @param source The data to convert
 @return The data in Base64-encoded form
 @throw NullPointerExceptionif source array is null
 @since 1.4
 */
+ (NSString *)encodeBytesWithByteArray:(IOSByteArray *)source;

/*!
 @brief Encodes a byte array into Base64 notation.
 <p>
  Example options:@code

    GZIP: gzip-compresses object before encoding it.
    DO_BREAK_LINES: break lines at 76 characters
          <i>Note: Technically, this makes your encoding non-compliant.</i>
   
@endcode
  <p>
  Example: <code>encodeBytes( myData, Base64.GZIP )</code> or 
 <p>
  Example: <code>encodeBytes( myData, Base64.GZIP | Base64.DO_BREAK_LINES )</code>
    
 <p>As of v 2.3, if there is an error with the GZIP stream,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned a null value, but
  in retrospect that's a pretty poor way to handle it.</p>
 @param source The data to convert
 @param options Specified options
 @return The Base64-encoded data as a String
 - seealso: Base64#GZIP
 - seealso: Base64#DO_BREAK_LINES
 @throw java.io.IOExceptionif there is an error
 @throw NullPointerExceptionif source array is null
 @since 2.0
 */
+ (NSString *)encodeBytesWithByteArray:(IOSByteArray *)source
                               withInt:(jint)options;

/*!
 @brief Encodes a byte array into Base64 notation.
 Does not GZip-compress data.
    
 <p>As of v 2.3, if there is an error,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned a null value, but
  in retrospect that's a pretty poor way to handle it.</p>
 @param source The data to convert
 @param off Offset in array where conversion should begin
 @param len Length of data to convert
 @return The Base64-encoded data as a String
 @throw NullPointerExceptionif source array is null
 @throw IllegalArgumentExceptionif source array, offset, or length are invalid
 @since 1.4
 */
+ (NSString *)encodeBytesWithByteArray:(IOSByteArray *)source
                               withInt:(jint)off
                               withInt:(jint)len;

/*!
 @brief Encodes a byte array into Base64 notation.
 <p>
  Example options:@code

    GZIP: gzip-compresses object before encoding it.
    DO_BREAK_LINES: break lines at 76 characters
          <i>Note: Technically, this makes your encoding non-compliant.</i>
   
@endcode
  <p>
  Example: <code>encodeBytes( myData, Base64.GZIP )</code> or 
 <p>
  Example: <code>encodeBytes( myData, Base64.GZIP | Base64.DO_BREAK_LINES )</code>
    
 <p>As of v 2.3, if there is an error with the GZIP stream,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned a null value, but
  in retrospect that's a pretty poor way to handle it.</p>
 @param source The data to convert
 @param off Offset in array where conversion should begin
 @param len Length of data to convert
 @param options Specified options
 @return The Base64-encoded data as a String
 - seealso: Base64#GZIP
 - seealso: Base64#DO_BREAK_LINES
 @throw java.io.IOExceptionif there is an error
 @throw NullPointerExceptionif source array is null
 @throw IllegalArgumentExceptionif source array, offset, or length are invalid
 @since 2.0
 */
+ (NSString *)encodeBytesWithByteArray:(IOSByteArray *)source
                               withInt:(jint)off
                               withInt:(jint)len
                               withInt:(jint)options;

/*!
 @brief Similar to <code>encodeBytes(byte[])</code> but returns
  a byte array instead of instantiating a String.This is more efficient
  if you're working with I/O streams and have large data sets to encode.
 @param source The data to convert
 @return The Base64-encoded data as a byte[] (of ASCII characters)
 @throw NullPointerExceptionif source array is null
 @since 2.3.1
 */
+ (IOSByteArray *)encodeBytesToBytesWithByteArray:(IOSByteArray *)source;

/*!
 @brief Similar to <code>int, int, int)</code> but returns
  a byte array instead of instantiating a String.This is more efficient
  if you're working with I/O streams and have large data sets to encode.
 @param source The data to convert
 @param off Offset in array where conversion should begin
 @param len Length of data to convert
 @param options Specified options
 @return The Base64-encoded data as a String
 - seealso: Base64#GZIP
 - seealso: Base64#DO_BREAK_LINES
 @throw java.io.IOExceptionif there is an error
 @throw NullPointerExceptionif source array is null
 @throw IllegalArgumentExceptionif source array, offset, or length are invalid
 @since 2.3.1
 */
+ (IOSByteArray *)encodeBytesToBytesWithByteArray:(IOSByteArray *)source
                                          withInt:(jint)off
                                          withInt:(jint)len
                                          withInt:(jint)options;

/*!
 @brief Reads <tt>infile</tt> and encodes it to <tt>outfile</tt>.
 @param infile Input file
 @param outfile Output file
 @throw java.io.IOExceptionif there is an error
 @since 2.2
 */
+ (void)encodeFileToFileWithNSString:(NSString *)infile
                        withNSString:(NSString *)outfile;

/*!
 @brief Convenience method for reading a binary file
  and base64-encoding it.
 <p>As of v 2.3, if there is a error,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned false, but
  in retrospect that's a pretty poor way to handle it.</p>
 @param filename Filename for reading binary data
 @return base64-encoded string
 @throw java.io.IOExceptionif there is an error
 @since 2.1
 */
+ (NSString *)encodeFromFileWithNSString:(NSString *)filename;

/*!
 @brief Serializes an object and returns the Base64-encoded
  version of that serialized object.
 <p>As of v 2.3, if the object
  cannot be serialized or there is another error,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned a null value, but
  in retrospect that's a pretty poor way to handle it.</p>
  
  The object is not GZip-compressed before being encoded.
 @param serializableObject The object to encode
 @return The Base64-encoded object
 @throw java.io.IOExceptionif there is an error
 @throw NullPointerExceptionif serializedObject is null
 @since 1.4
 */
+ (NSString *)encodeObjectWithJavaIoSerializable:(id<JavaIoSerializable>)serializableObject;

/*!
 @brief Serializes an object and returns the Base64-encoded
  version of that serialized object.
 <p>As of v 2.3, if the object
  cannot be serialized or there is another error,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned a null value, but
  in retrospect that's a pretty poor way to handle it.</p>
  
  The object is not GZip-compressed before being encoded. 
 <p>
  Example options:@code

    GZIP: gzip-compresses object before encoding it.
    DO_BREAK_LINES: break lines at 76 characters 
  
@endcode
  <p>
  Example: <code>encodeObject( myObj, Base64.GZIP )</code> or 
 <p>
  Example: <code>encodeObject( myObj, Base64.GZIP | Base64.DO_BREAK_LINES )</code>
 @param serializableObject The object to encode
 @param options Specified options
 @return The Base64-encoded object
 - seealso: Base64#GZIP
 - seealso: Base64#DO_BREAK_LINES
 @throw java.io.IOExceptionif there is an error
 @since 2.0
 */
+ (NSString *)encodeObjectWithJavaIoSerializable:(id<JavaIoSerializable>)serializableObject
                                         withInt:(jint)options;

/*!
 @brief Convenience method for encoding data to a file.
 <p>As of v 2.3, if there is a error,
  the method will throw an java.io.IOException. <b>This is new to v2.3!</b>
  In earlier versions, it just returned false, but
  in retrospect that's a pretty poor way to handle it.</p>
 @param dataToEncode byte array of data to encode in base64 form
 @param filename Filename for saving encoded data
 @throw java.io.IOExceptionif there is an error
 @throw NullPointerExceptionif dataToEncode is null
 @since 2.1
 */
+ (void)encodeToFileWithByteArray:(IOSByteArray *)dataToEncode
                     withNSString:(NSString *)filename;

@end

J2OBJC_STATIC_INIT(NetIharderBase64)

/*!
 @brief No options specified.Value is zero.
 */
inline jint NetIharderBase64_get_NO_OPTIONS(void);
#define NetIharderBase64_NO_OPTIONS 0
J2OBJC_STATIC_FIELD_CONSTANT(NetIharderBase64, NO_OPTIONS, jint)

/*!
 @brief Specify encoding in first bit.Value is one.
 */
inline jint NetIharderBase64_get_ENCODE(void);
#define NetIharderBase64_ENCODE 1
J2OBJC_STATIC_FIELD_CONSTANT(NetIharderBase64, ENCODE, jint)

/*!
 @brief Specify decoding in first bit.Value is zero.
 */
inline jint NetIharderBase64_get_DECODE(void);
#define NetIharderBase64_DECODE 0
J2OBJC_STATIC_FIELD_CONSTANT(NetIharderBase64, DECODE, jint)

/*!
 @brief Specify that data should be gzip-compressed in second bit.Value is two.
 */
inline jint NetIharderBase64_get_GZIP(void);
#define NetIharderBase64_GZIP 2
J2OBJC_STATIC_FIELD_CONSTANT(NetIharderBase64, GZIP, jint)

/*!
 @brief Do break lines when encoding.Value is 8.
 */
inline jint NetIharderBase64_get_DO_BREAK_LINES(void);
#define NetIharderBase64_DO_BREAK_LINES 8
J2OBJC_STATIC_FIELD_CONSTANT(NetIharderBase64, DO_BREAK_LINES, jint)

/*!
 @brief Encode using Base64-like encoding that is URL- and Filename-safe as described
  in Section 4 of RFC3548:  
 <a href="http://www.faqs.org/rfcs/rfc3548.html">http://www.faqs.org/rfcs/rfc3548.html</a>.
 It is important to note that data encoded this way is <em>not</em> officially valid Base64, 
  or at the very least should not be called Base64 without also specifying that is
  was encoded using the URL- and Filename-safe dialect.
 */
inline jint NetIharderBase64_get_URL_SAFE(void);
#define NetIharderBase64_URL_SAFE 16
J2OBJC_STATIC_FIELD_CONSTANT(NetIharderBase64, URL_SAFE, jint)

/*!
 @brief Encode using the special "ordered" dialect of Base64 described here: 
 <a href="http://www.faqs.org/qa/rfcc-1940.html">http://www.faqs.org/qa/rfcc-1940.html</a>.
 */
inline jint NetIharderBase64_get_ORDERED(void);
#define NetIharderBase64_ORDERED 32
J2OBJC_STATIC_FIELD_CONSTANT(NetIharderBase64, ORDERED, jint)

FOUNDATION_EXPORT void NetIharderBase64_encodeWithJavaNioByteBuffer_withJavaNioByteBuffer_(JavaNioByteBuffer *raw, JavaNioByteBuffer *encoded);

FOUNDATION_EXPORT void NetIharderBase64_encodeWithJavaNioByteBuffer_withJavaNioCharBuffer_(JavaNioByteBuffer *raw, JavaNioCharBuffer *encoded);

FOUNDATION_EXPORT NSString *NetIharderBase64_encodeObjectWithJavaIoSerializable_(id<JavaIoSerializable> serializableObject);

FOUNDATION_EXPORT NSString *NetIharderBase64_encodeObjectWithJavaIoSerializable_withInt_(id<JavaIoSerializable> serializableObject, jint options);

FOUNDATION_EXPORT NSString *NetIharderBase64_encodeBytesWithByteArray_(IOSByteArray *source);

FOUNDATION_EXPORT NSString *NetIharderBase64_encodeBytesWithByteArray_withInt_(IOSByteArray *source, jint options);

FOUNDATION_EXPORT NSString *NetIharderBase64_encodeBytesWithByteArray_withInt_withInt_(IOSByteArray *source, jint off, jint len);

FOUNDATION_EXPORT NSString *NetIharderBase64_encodeBytesWithByteArray_withInt_withInt_withInt_(IOSByteArray *source, jint off, jint len, jint options);

FOUNDATION_EXPORT IOSByteArray *NetIharderBase64_encodeBytesToBytesWithByteArray_(IOSByteArray *source);

FOUNDATION_EXPORT IOSByteArray *NetIharderBase64_encodeBytesToBytesWithByteArray_withInt_withInt_withInt_(IOSByteArray *source, jint off, jint len, jint options);

FOUNDATION_EXPORT IOSByteArray *NetIharderBase64_decodeWithByteArray_(IOSByteArray *source);

FOUNDATION_EXPORT IOSByteArray *NetIharderBase64_decodeWithByteArray_withInt_withInt_withInt_(IOSByteArray *source, jint off, jint len, jint options);

FOUNDATION_EXPORT IOSByteArray *NetIharderBase64_decodeWithNSString_(NSString *s);

FOUNDATION_EXPORT IOSByteArray *NetIharderBase64_decodeWithNSString_withInt_(NSString *s, jint options);

FOUNDATION_EXPORT id NetIharderBase64_decodeToObjectWithNSString_(NSString *encodedObject);

FOUNDATION_EXPORT void NetIharderBase64_encodeToFileWithByteArray_withNSString_(IOSByteArray *dataToEncode, NSString *filename);

FOUNDATION_EXPORT void NetIharderBase64_decodeToFileWithNSString_withNSString_(NSString *dataToDecode, NSString *filename);

FOUNDATION_EXPORT IOSByteArray *NetIharderBase64_decodeFromFileWithNSString_(NSString *filename);

FOUNDATION_EXPORT NSString *NetIharderBase64_encodeFromFileWithNSString_(NSString *filename);

FOUNDATION_EXPORT void NetIharderBase64_encodeFileToFileWithNSString_withNSString_(NSString *infile, NSString *outfile);

FOUNDATION_EXPORT void NetIharderBase64_decodeFileToFileWithNSString_withNSString_(NSString *infile, NSString *outfile);

J2OBJC_TYPE_LITERAL_HEADER(NetIharderBase64)

#endif

#if !defined (NetIharderBase64_InputStream_) && (INCLUDE_ALL_NetIharderBase64 || defined(INCLUDE_NetIharderBase64_InputStream))
#define NetIharderBase64_InputStream_

#define RESTRICT_JavaIoFilterInputStream 1
#define INCLUDE_JavaIoFilterInputStream 1
#include "java/io/FilterInputStream.h"

@class IOSByteArray;
@class JavaIoInputStream;

/*!
 @brief A <code>Base64.InputStream</code> will read data from another 
 <tt>java.io.InputStream</tt>, given in the constructor,
  and encode/decode to/from Base64 notation on the fly.
 - seealso: Base64
 @since 1.3
 */
@interface NetIharderBase64_InputStream : JavaIoFilterInputStream

#pragma mark Public

/*!
 @brief Constructs a <code>Base64.InputStream</code> in DECODE mode.
 @param inArg the  <tt> java.io.InputStream </tt>  from which to read data.
 @since 1.3
 */
- (instancetype __nonnull)initWithJavaIoInputStream:(JavaIoInputStream *)inArg;

/*!
 @brief Constructs a <code>Base64.InputStream</code> in
  either ENCODE or DECODE mode.
 <p>
  Valid options:@code

    ENCODE or DECODE: Encode or Decode as data is read.
    DO_BREAK_LINES: break lines at 76 characters
      (only meaningful when encoding)</i>
   
@endcode
  <p>
  Example: <code>new Base64.InputStream( in, Base64.DECODE )</code>
 @param inArg the  <tt> java.io.InputStream </tt>  from which to read data.
 @param options Specified options
 - seealso: Base64#ENCODE
 - seealso: Base64#DECODE
 - seealso: Base64#DO_BREAK_LINES
 @since 2.0
 */
- (instancetype __nonnull)initWithJavaIoInputStream:(JavaIoInputStream *)inArg
                                            withInt:(jint)options;

/*!
 @brief Reads enough of the input stream to convert
  to/from Base64 and returns the next byte.
 @return next byte
 @since 1.3
 */
- (jint)read;

/*!
 @brief Calls <code>read()</code> repeatedly until the end of stream
  is reached or <var>len</var> bytes are read.
 Returns number of bytes read into array or -1 if
  end of stream is encountered.
 @param dest array to hold values
 @param off offset for array
 @param len max number of bytes to read into array
 @return bytes read into array or -1 if end of stream is encountered.
 @since 1.3
 */
- (jint)readWithByteArray:(IOSByteArray *)dest
                  withInt:(jint)off
                  withInt:(jint)len;

@end

J2OBJC_EMPTY_STATIC_INIT(NetIharderBase64_InputStream)

FOUNDATION_EXPORT void NetIharderBase64_InputStream_initWithJavaIoInputStream_(NetIharderBase64_InputStream *self, JavaIoInputStream *inArg);

FOUNDATION_EXPORT NetIharderBase64_InputStream *new_NetIharderBase64_InputStream_initWithJavaIoInputStream_(JavaIoInputStream *inArg) NS_RETURNS_RETAINED;

FOUNDATION_EXPORT NetIharderBase64_InputStream *create_NetIharderBase64_InputStream_initWithJavaIoInputStream_(JavaIoInputStream *inArg);

FOUNDATION_EXPORT void NetIharderBase64_InputStream_initWithJavaIoInputStream_withInt_(NetIharderBase64_InputStream *self, JavaIoInputStream *inArg, jint options);

FOUNDATION_EXPORT NetIharderBase64_InputStream *new_NetIharderBase64_InputStream_initWithJavaIoInputStream_withInt_(JavaIoInputStream *inArg, jint options) NS_RETURNS_RETAINED;

FOUNDATION_EXPORT NetIharderBase64_InputStream *create_NetIharderBase64_InputStream_initWithJavaIoInputStream_withInt_(JavaIoInputStream *inArg, jint options);

J2OBJC_TYPE_LITERAL_HEADER(NetIharderBase64_InputStream)

#endif

#if !defined (NetIharderBase64_OutputStream_) && (INCLUDE_ALL_NetIharderBase64 || defined(INCLUDE_NetIharderBase64_OutputStream))
#define NetIharderBase64_OutputStream_

#define RESTRICT_JavaIoFilterOutputStream 1
#define INCLUDE_JavaIoFilterOutputStream 1
#include "java/io/FilterOutputStream.h"

@class IOSByteArray;
@class JavaIoOutputStream;

/*!
 @brief A <code>Base64.OutputStream</code> will write data to another 
 <tt>java.io.OutputStream</tt>, given in the constructor,
  and encode/decode to/from Base64 notation on the fly.
 - seealso: Base64
 @since 1.3
 */
@interface NetIharderBase64_OutputStream : JavaIoFilterOutputStream

#pragma mark Public

/*!
 @brief Constructs a <code>Base64.OutputStream</code> in ENCODE mode.
 @param outArg the  <tt> java.io.OutputStream </tt>  to which data will be written.
 @since 1.3
 */
- (instancetype __nonnull)initWithJavaIoOutputStream:(JavaIoOutputStream *)outArg;

/*!
 @brief Constructs a <code>Base64.OutputStream</code> in
  either ENCODE or DECODE mode.
 <p>
  Valid options:@code

    ENCODE or DECODE: Encode or Decode as data is read.
    DO_BREAK_LINES: don't break lines at 76 characters
      (only meaningful when encoding)</i>
   
@endcode
  <p>
  Example: <code>new Base64.OutputStream( out, Base64.ENCODE )</code>
 @param outArg the  <tt> java.io.OutputStream </tt>  to which data will be written.
 @param options Specified options.
 - seealso: Base64#ENCODE
 - seealso: Base64#DECODE
 - seealso: Base64#DO_BREAK_LINES
 @since 1.3
 */
- (instancetype __nonnull)initWithJavaIoOutputStream:(JavaIoOutputStream *)outArg
                                             withInt:(jint)options;

/*!
 @brief Flushes and closes (I think, in the superclass) the stream.
 @since 1.3
 */
- (void)close;

/*!
 @brief Flushes the stream (and the enclosing streams).
 @throw java.io.IOException
 @since 2.3
 */
- (void)flush;

/*!
 @brief Method added by PHIL.
 [Thanks, PHIL. -Rob]
  This pads the buffer without closing the stream.
 @throw java.io.IOExceptionif there's an error.
 */
- (void)flushBase64;

/*!
 @brief Resumes encoding of the stream.
 May be helpful if you need to embed a piece of
  base64-encoded data in a stream.
 @since 1.5.1
 */
- (void)resumeEncoding;

/*!
 @brief Suspends encoding of the stream.
 May be helpful if you need to embed a piece of
  base64-encoded data in a stream.
 @throw java.io.IOExceptionif there's an error flushing
 @since 1.5.1
 */
- (void)suspendEncoding;

/*!
 @brief Calls <code>write(int)</code> repeatedly until <var>len</var> 
  bytes are written.
 @param theBytes array from which to read bytes
 @param off offset for array
 @param len max number of bytes to read into array
 @since 1.3
 */
- (void)writeWithByteArray:(IOSByteArray *)theBytes
                   withInt:(jint)off
                   withInt:(jint)len;

/*!
 @brief Writes the byte to the output stream after
  converting to/from Base64 notation.
 When encoding, bytes are buffered three
  at a time before the output stream actually
  gets a write() call.
  When decoding, bytes are buffered four
  at a time.
 @param theByte the byte to write
 @since 1.3
 */
- (void)writeWithInt:(jint)theByte;

@end

J2OBJC_EMPTY_STATIC_INIT(NetIharderBase64_OutputStream)

FOUNDATION_EXPORT void NetIharderBase64_OutputStream_initWithJavaIoOutputStream_(NetIharderBase64_OutputStream *self, JavaIoOutputStream *outArg);

FOUNDATION_EXPORT NetIharderBase64_OutputStream *new_NetIharderBase64_OutputStream_initWithJavaIoOutputStream_(JavaIoOutputStream *outArg) NS_RETURNS_RETAINED;

FOUNDATION_EXPORT NetIharderBase64_OutputStream *create_NetIharderBase64_OutputStream_initWithJavaIoOutputStream_(JavaIoOutputStream *outArg);

FOUNDATION_EXPORT void NetIharderBase64_OutputStream_initWithJavaIoOutputStream_withInt_(NetIharderBase64_OutputStream *self, JavaIoOutputStream *outArg, jint options);

FOUNDATION_EXPORT NetIharderBase64_OutputStream *new_NetIharderBase64_OutputStream_initWithJavaIoOutputStream_withInt_(JavaIoOutputStream *outArg, jint options) NS_RETURNS_RETAINED;

FOUNDATION_EXPORT NetIharderBase64_OutputStream *create_NetIharderBase64_OutputStream_initWithJavaIoOutputStream_withInt_(JavaIoOutputStream *outArg, jint options);

J2OBJC_TYPE_LITERAL_HEADER(NetIharderBase64_OutputStream)

#endif


#if __has_feature(nullability)
#pragma clang diagnostic pop
#endif
#pragma pop_macro("INCLUDE_ALL_NetIharderBase64")
