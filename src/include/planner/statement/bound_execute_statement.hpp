//===----------------------------------------------------------------------===//
//                         DuckDB
//
// planner/statement/bound_execute_statement.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "planner/bound_sql_statement.hpp"

#include "catalog/catalog_entry/prepared_statement_catalog_entry.hpp"

namespace duckdb {
//! Bound equivalent to ExecuteStatement
class BoundExecuteStatement : public BoundSQLStatement {
public:
	BoundExecuteStatement() : BoundSQLStatement(StatementType::EXECUTE) {
	}

	//! The substitution values
	vector<Value> values;
	//! The prepared statement to execute
	PreparedStatementCatalogEntry *prep;
public:
	vector<string> GetNames() override {
		return prep->names;
	}
};
} // namespace duckdb