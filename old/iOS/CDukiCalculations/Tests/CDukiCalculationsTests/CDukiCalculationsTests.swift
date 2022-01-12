import XCTest
@testable import CDukiCalculations

final class CDukiCalculationsTests: XCTestCase {
    func testExample() throws {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct
        // results.
        var array: [Int64] = [9, 8, 7, 6]
        let str = try XCTUnwrap(demo(true, 10, 1.23, &array, array.count))
        XCTAssertEqual(String(cString: str), "boolean: true, integer: 10, floatingPoint: 1.230000, integerArray sum: 30")
        str.deallocate()
    }
}
